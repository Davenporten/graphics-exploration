#include <vector>
#include <cstdint>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

class Pixel {
    private:
        int x;
        int y;

    public:
        Pixel(int x, int y) : x(x), y(y) {}

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
};

class Rasterizer {
    private:
        int width;
        int height;
        std::vector<uint32_t> framebuffer;  // This will store RGBA colors (8 bits each)

        GLuint textureID;

        int getPixelPoint(int x, int y) {
            return y * this->width + x;
        }

        bool isOutOfBounds(int x, int y) {
            return x < 0 || y < 0 || x >= width || y >= height;
        }

    public:
        Rasterizer(int w, int h) : width(w), height(h) {
            // Your initialization code here
            framebuffer.resize(width * height, 0);
        }

        void setPixel(int x, int y, uint32_t color) {
            // Your code to set a pixel here
            if (isOutOfBounds(x, y)) {
                cout << "Out of bounds\n";
                return;
            }

            framebuffer[getPixelPoint(x, y)] = color;
        }

        uint32_t getPixel(int x, int y) {
            if (isOutOfBounds(x, y)) {
                cout << "Pixel does not exist. Out of bounds.\n";
            }
            return this->framebuffer[getPixelPoint(x, y)];
        }

        GLuint getTextureID() {
            return textureID;
        }

        GLuint specify2DTexture() {
           glGenTextures(1, &textureID);
           glBindTexture(GL_TEXTURE_2D, textureID);
       
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
       
           glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, framebuffer.data());

           return textureID;
        }

        void updateTexture(int x, int y, uint32_t color) {
            setPixel(x, y, color);

            glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &framebuffer[getPixelPoint(x, y)]);
        }
};

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"                // Output color of the pixel
    "in vec2 TexCoord;\n"                  // Input from vertex shader
    "uniform sampler2D ourTexture;\n"      // Our texture sampler
    "void main()\n"
    "{\n"
    "    FragColor = texture(ourTexture, TexCoord);\n"
    "}\0";

int main() {
    // Create a small rasterizer (like 20x20 pixels)
    Rasterizer rasterizer(20, 20);
    
    // Your test code will go here
    rasterizer.setPixel(1, 1, 0x25);
    cout << hex << rasterizer.getPixel(1, 1) << "\n";

    rasterizer.setPixel(21, 3, 0x35);

    rasterizer.setPixel(3, 21, 0x35);

     // Initialize GLFW
     cout << "Start\n";
    if (!glfwInit()) {
        cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set OpenGL version (example: 3.3 Core)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on macOS
#endif

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    rasterizer.specify2DTexture();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    } 

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    memset(infoLog, 0, sizeof infoLog);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return -1;
    }
    
    // Clean up shaders as they're linked into program and no longer needed
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    while (!glfwWindowShouldClose(window)) {
        //glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    cout << "Done\n";

    return 0;
}