#include "framebuffer.h"

int main() {
    // Colores
    Color navyBlue(0, 0, 128);
    Color white(255, 255, 255);
    Color red(255, 0, 0);
    Color black(0, 0, 0);

    // Color de fondo y limpiar el buffer
    setClearColor(white);
    clear();

    // Color de dibujo
    setCurrentColor(navyBlue);

    // Dibujar un solo punto
    render_point(400, 300);
    renderBuffer("point.bmp");
    clear();

    // Dibujar una línea
    Vertex2 lineStart = { 100, 100 };
    Vertex2 lineEnd = { 700, 500 };

    render_line(lineStart, lineEnd);
    renderBuffer("line.bmp");
    clear();

    // Dibujar un polígono con relleno y borde
    Vertex2 polygonPoints[] = { {200, 200}, {300, 100}, {400, 200}, {300, 300} };
    int numPoints = sizeof(polygonPoints) / sizeof(polygonPoints[0]);

    Polygon polygon;
    for (int i = 0; i < numPoints; i++) {
        polygon.vertices.push_back(polygonPoints[i]);
    }
    polygon.fillColor = red;
    polygon.borderColor = black;

    drawPolygon(polygon);

    return 0;
}
