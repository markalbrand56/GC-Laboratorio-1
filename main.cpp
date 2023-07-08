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

    // Dibujar un solo punto
    Vertex2 point1 = { 400, 300 };
    point(point1);

    renderBuffer("single_point.bmp");

    // Dibujar una línea
    Vertex2 lineStart = { 100, 100 };
    Vertex2 lineEnd = { 700, 500 };

    for (int i = 0; i < 100; ++i) {
        Vertex2 linePoint = {
            lineStart.x + (lineEnd.x - lineStart.x) * i / 100,
            lineStart.y + (lineEnd.y - lineStart.y) * i / 100
        };
        point(linePoint);
    }

    renderBuffer("line.bmp");

}