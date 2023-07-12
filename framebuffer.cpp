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
        point({ x0, y0 });

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

void drawPolygon(const Polygon& polygon) {
    setCurrentColor(polygon.fillColor);

    int numVertices = static_cast<int>(polygon.vertices.size());
    if (numVertices < 3) {
        return;
    }

    float yMin = SCREEN_HEIGHT;
    float yMax = 0;

    for (const Vertex2& vertex : polygon.vertices) {
        if (vertex.y < yMin) {
            yMin = vertex.y;
        }
        if (vertex.y > yMax) {
            yMax = vertex.y;
        }
    }

    for (int y = static_cast<int>(yMin); y <= yMax; y++) {
        std::vector<float> intersections;

        for (int i = 0; i < numVertices; i++) {
            const Vertex2& currentVertex = polygon.vertices[i];
            const Vertex2& nextVertex = polygon.vertices[(i + 1) % numVertices];

            if ((currentVertex.y <= y && nextVertex.y > y) || (currentVertex.y > y && nextVertex.y <= y)) {
                float intersectionX = currentVertex.x + (y - currentVertex.y) * (nextVertex.x - currentVertex.x) / (nextVertex.y - currentVertex.y);
                intersections.push_back(intersectionX);
            }
        }

        std::sort(intersections.begin(), intersections.end());

        int numIntersections = static_cast<int>(intersections.size());
        if (numIntersections < 2) {
            continue;
        }

        for (int i = 0; i < numIntersections - 1; i += 2) {
            int startX = static_cast<int>(intersections[i]);
            int endX = static_cast<int>(intersections[i + 1]);

            for (int x = startX; x < endX; x++) {
                point({ (x), (y) });
            }
        }
    }


    setCurrentColor(polygon.borderColor);

    for (int i = 0; i < numVertices - 1; i++) {
        render_line(polygon.vertices[i], polygon.vertices[i + 1]);
    }

    render_line(polygon.vertices[numVertices - 1], polygon.vertices[0]);

    renderBuffer("filled_polygon.bmp");
    clear();
}
