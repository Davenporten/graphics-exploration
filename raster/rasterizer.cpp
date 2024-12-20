#include <vector>
#include <cstdint>
#include <iostream>

using namespace std;

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

    return 0;
}