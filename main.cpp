#include "framebuffer.h"
#include "bmp_writer.h"

void render();

int main() {
    render();
    return 0;
}

void render() {
    Color navyBlue(0, 0, 128);
    Color white(255, 255, 255);

    setClearColor(navyBlue);
    clear();

    setCurrentColor(white);

    // Dibujar un cuadrado en el centro de la pantalla
    int size = 100;
    int xStart = (SCREEN_WIDTH - size) / 2;
    int yStart = (SCREEN_HEIGHT - size) / 2;
    for (int y = yStart; y < yStart + size; ++y) {
        for (int x = xStart; x < xStart + size; ++x) {
            point(Vertex2{x, y});
        }
    }

    renderBuffer();
}

