#include "framebuffer.h"

void render_point(int x, int y);
void render_line(Vertex2 start, Vertex2 end);
void render_polygon(Vertex2* points, int numPoints);

int main() {
    // Colores
    Color navyBlue(0, 0, 128);
    Color white(255, 255, 255);

    // Color de fondo y limpiar el buffer
    setClearColor(navyBlue);
    clear();

    // Color de dibujo
    setCurrentColor(white);

    // Dibujar un solo punto
    render_point(400,300);
    renderBuffer("point.bmp");
    clear();

    // Dibujar una línea
    Vertex2 lineStart = { 100, 100 };
    Vertex2 lineEnd = { 700, 500 };

    render_line(lineStart, lineEnd);
    renderBuffer("line.bmp");
    clear();

    // Dibujar un polígono
    Vertex2 polygonPoints[] = { {200, 200}, {300, 100}, {400, 200}, {300, 300} };
    int numPoints = sizeof(polygonPoints) / sizeof(polygonPoints[0]);

    render_polygon(polygonPoints, numPoints);
    renderBuffer("polygon.bmp");
    clear();

    return 0;
}

void render_point(int x, int y) {
    // Dibujar un solo punto
    Vertex2 point1 = { x, y };
    point(point1);
}

void render_line(Vertex2 start, Vertex2 end) {
    int x0 = static_cast<int>(start.x);
    int y0 = static_cast<int>(start.y);
    int x1 = static_cast<int>(end.x);
    int y1 = static_cast<int>(end.y);

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        point({ static_cast<float>(x0), static_cast<float>(y0) });

        if (x0 == x1 && y0 == y1) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void render_polygon(Vertex2* points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        Vertex2 startPoint = points[i];
        Vertex2 endPoint = points[(i + 1) % numPoints];

        render_line(startPoint, endPoint);
    }
}
