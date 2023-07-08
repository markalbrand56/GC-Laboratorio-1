#include <vector>
#include "framebuffer.h"
#include "bmp_writer.h"

std::vector<Color> framebuffer(SCREEN_WIDTH * SCREEN_HEIGHT);
Color clearColor(0, 0, 0);
Color currentColor(255, 255, 255);

void clear() {
    for (auto & i : framebuffer) {
        i = clearColor;
    }
}

void setCurrentColor(Color color) {
    currentColor = color;
}

void setClearColor(Color color) {
    clearColor = color;
}

void point(Vertex2 vertex) {
    int x = vertex.x;
    int y = vertex.y;
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        framebuffer[y * SCREEN_WIDTH + x] = currentColor;
    }
}

void renderBuffer(const char *filename) {
    writeBMP(filename);
}
