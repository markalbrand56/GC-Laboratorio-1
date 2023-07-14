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

    // (413, 177) (448, 159) (502, 88) (553, 53) (535, 36) (676, 37) (660, 52)
    //(750, 145) (761, 179) (672, 192) (659, 214) (615, 214) (632, 230) (580, 230)
    //(597, 215) (552, 214) (517, 144) (466, 180)

    // Este debe ser verde con orilla blanca

    Polygon polygon4;

    polygon4.vertices.push_back({ 413, 177 });
    polygon4.vertices.push_back({ 448, 159 });
    polygon4.vertices.push_back({ 502, 88 });
    polygon4.vertices.push_back({ 553, 53 });
    polygon4.vertices.push_back({ 535, 36 });
    polygon4.vertices.push_back({ 676, 37 });
    polygon4.vertices.push_back({ 660, 52 });
    polygon4.vertices.push_back({ 750, 145 });
    polygon4.vertices.push_back({ 761, 179 });
    polygon4.vertices.push_back({ 672, 192 });
    polygon4.vertices.push_back({ 659, 214 });
    polygon4.vertices.push_back({ 615, 214 });
    polygon4.vertices.push_back({ 632, 230 });
    polygon4.vertices.push_back({ 580, 230 });
    polygon4.vertices.push_back({ 597, 215 });
    polygon4.vertices.push_back({ 552, 214 });
    polygon4.vertices.push_back({ 517, 144 });
    polygon4.vertices.push_back({ 466, 180 });
    polygon4.fillColor = Color(0, 255, 0);
    polygon4.borderColor = white;

    polygons.push_back(polygon4);

    // (682, 175) (708, 120) (735, 148) (739, 170)

    Polygon polygon5;

    polygon5.vertices.push_back({ 682, 175 });
    polygon5.vertices.push_back({ 708, 120 });
    polygon5.vertices.push_back({ 735, 148 });
    polygon5.vertices.push_back({ 739, 170 });
    polygon5.fillColor = black;
    polygon5.borderColor = black;

    polygons.push_back(polygon5);

    drawPolygons(polygons, "polygon4.bmp");

    return 0;
}
