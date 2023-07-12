#pragma once
#include <string>

// Definiciones para el archivo BMP
const int reserved = 0;
const int pixelDataOffset = 54;
const int headerSize = 40;
const short planes = 1;
const short bitDepth = 24;
const int compression = 0;
const int horizontalResolution = 0;
const int verticalResolution = 0;
const int colors = 0;
const int importantColors = 0;

// Función para escribir el archivo BMP
void writeBMP(const std::string& filename);
