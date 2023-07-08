#include <iostream>
#include <vector>
#include "color.h"

std::vector<Color> framebuffer;
Color clearColor(0, 0, 0);

void clear() {
    for (int i = 0; i < framebuffer.size(); ++i) {
        framebuffer[i] = clearColor;
    }
}

int main() {
    // Color red, green, blue se inicializan mediante la sobrecarga del operador de asignación
    Color red;
    red = Color(255, 0, 0);
    Color green;
    green = Color(0, 255, 0);
    Color blue;
    blue = Color(0, 0, 255);

    // Imprimir los colores utilizando el operador de salida sobrecargado
    std::cout << "Red: " << red << std::endl;
    std::cout << "Green: " << green << std::endl;
    std::cout << "Blue: " << blue << std::endl;

    // Sumar dos colores
    Color sum = red + green;
    std::cout << "Sum: " << sum << std::endl;

    // Multiplicar un color por un flotante
    Color multiplied = blue * 0.5f;
    std::cout << "Multiplied: " << multiplied << std::endl;

    int width = 800;
    int height = 600;

    // Inicializar el framebuffer con el tamaño adecuado
    framebuffer.resize(width * height);

    // Limpiar el framebuffer con el color clearColor
    clear();

    // Ejemplo: Establecer un píxel en el framebuffer
    int x = 400;
    int y = 300;
    framebuffer[y * width + x] = red;

    // Ejemplo: Imprimir el color del píxel establecido
    Color pixelColor = framebuffer[y * width + x];
    std::cout << "Color del pixel en la posicion (" << x << ", " << y << "): "
              << pixelColor << std::endl;

    return 0;
}
