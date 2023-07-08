#pragma once
#include <string>
#include <vector>
#include "color.h"

// Tamaño de la pantalla
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Definiciones de color y estructuras
struct Vertex2 {
    int x, y;
};

// Variables globales del framebuffer
extern std::vector<Color> framebuffer;
extern Color clearColor;
extern Color currentColor;

// Funciones del framebuffer
void clear();
void setCurrentColor(Color color);
void setClearColor(Color color);
void point(Vertex2 vertex);
void renderBuffer();
