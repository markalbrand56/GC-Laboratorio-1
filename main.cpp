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
}