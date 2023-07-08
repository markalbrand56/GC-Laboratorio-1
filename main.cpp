#include "framebuffer.h"

void render_point();
void render_line(Vertex2 start, Vertex2 end);

int main() {
    // Dibujar un solo punto
    render_point();

    // Dibujar una línea
    Vertex2 lineStart = { 100, 100 };
    Vertex2 lineEnd = { 700, 500 };

    render_line(lineStart, lineEnd);

    return 0;
}

void render_point() {
    // Colores
    Color navyBlue(0, 0, 128);
    Color white(255, 255, 255);

    // Color de fondo y limpiar el buffer
    setClearColor(navyBlue);
    clear();

    // Color de dibujo
    setCurrentColor(white);

    // Dibujar un solo punto
    Vertex2 point1 = { 400, 300 };
    point(point1);

    renderBuffer("single_point.bmp");
    clear(); // Limpiar el buffer
}

void render_line(Vertex2 start, Vertex2 end) {
    // Colores
    Color navyBlue(0, 0, 128);
    Color white(255, 255, 255);

    // Color de fondo y limpiar el buffer
    setClearColor(navyBlue);
    clear();

    // Color de dibujo
    setCurrentColor(white);

    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);
    int x = start.x;
    int y = start.y;

    while (x < end.x) {
        point({ x, y });
        if (d <= 0) {
            d += incrE;
            x++;
        } else {
            d += incrNE;
            x++;
            y++;
        }
    }

    renderBuffer("line.bmp");
    clear(); // Limpiar el buffer
}