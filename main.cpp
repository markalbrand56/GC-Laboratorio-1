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

// lineas verticales rojas
//void render() {
//    Color black(0, 0, 0);
//    Color white(255, 255, 255);
//    Color red(255, 0, 0);
//
//    setClearColor(black);
//    clear();
//
//    setCurrentColor(white);
//
//    // Dibujar un patrón de líneas diagonales rojas
//    int tileSize = 50;
//    for (int y = 0; y < SCREEN_HEIGHT; y += tileSize) {
//        for (int x = 0; x < SCREEN_WIDTH; x += tileSize) {
//            if ((x / tileSize + y / tileSize) % 2 == 0) {
//                setCurrentColor(red);
//            } else {
//                setCurrentColor(white);
//            }
//
//            for (int i = y; i < y + tileSize; ++i) {
//                for (int j = x; j < x + tileSize; ++j) {
//                    point(Vertex2{j, i});
//                }
//            }
//        }
//    }
//
//    renderBuffer();
//}
