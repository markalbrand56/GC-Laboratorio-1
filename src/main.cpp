#include "framebuffer.h"

int main() {
    // Colores
    Color white(255, 255, 255);
    Color black(0, 0, 0);
    Color navyBlue(0, 0, 128);
    Color red(255, 0, 0);
    Color yellow(255, 255, 0);

    clear();

    setClearColor(white);
    setCurrentColor(navyBlue);

    std::vector<Polygon> polygons;

    Polygon polygon1;

    // (165, 380) (185, 360) (180, 330) (207, 345) (233, 330) (230, 360) (250, 380) (220, 385) (205, 410) (193, 383)
    //  debe ser amarillo con orilla blanca

    polygon1.vertices.push_back({ 165, 380 });
    polygon1.vertices.push_back({ 185, 360 });
    polygon1.vertices.push_back({ 180, 330 });
    polygon1.vertices.push_back({ 207, 345 });
    polygon1.vertices.push_back({ 233, 330 });
    polygon1.vertices.push_back({ 230, 360 });
    polygon1.vertices.push_back({ 250, 380 });
    polygon1.vertices.push_back({ 220, 385 });
    polygon1.vertices.push_back({ 205, 410 });
    polygon1.vertices.push_back({ 193, 383 });
    polygon1.fillColor = yellow;
    polygon1.borderColor = white;

    polygons.push_back(polygon1);

//    drawPolygons(polygons, "polygon1.bmp");

    // (321, 335) (288, 286) (339, 251) (374, 302)
    //  Este debe ser azul con orilla blanca

    Polygon polygon2;

    polygon2.vertices.push_back({ 321, 335 });
    polygon2.vertices.push_back({ 288, 286 });
    polygon2.vertices.push_back({ 339, 251 });
    polygon2.vertices.push_back({ 374, 302 });
    polygon2.fillColor = navyBlue;
    polygon2.borderColor = white;

    polygons.push_back(polygon2);


    //(377, 249) (411, 197) (436, 249)
    // Este debe ser rojo con orilla blanca.

    Polygon polygon3;

    polygon3.vertices.push_back({ 377, 249 });
    polygon3.vertices.push_back({ 411, 197 });
    polygon3.vertices.push_back({ 436, 249 });
    polygon3.fillColor = red;
    polygon3.borderColor = white;

    polygons.push_back(polygon3);

    drawPolygons(polygons, "polygon3.bmp");

    return 0;
}
