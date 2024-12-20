#include <vector>
#include <cstdint>
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

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
};

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