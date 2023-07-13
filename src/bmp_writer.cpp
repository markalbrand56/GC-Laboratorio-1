#include <fstream>
#include "framebuffer.h"
#include "bmp_writer.h"

void writeBMP(const std::string& filename) {
    int dataSize = SCREEN_WIDTH * SCREEN_HEIGHT * 3;
    int fileSize = 54 + dataSize;

    std::ofstream file("../src/img/" + filename, std::ios::binary);

    // Header del archivo BMP
    file << "BM";
    file.write(reinterpret_cast<const char*>(&fileSize), 4);
    file.write(reinterpret_cast<const char*>(&reserved), 4);
    file.write(reinterpret_cast<const char*>(&pixelDataOffset), 4);
    file.write(reinterpret_cast<const char*>(&headerSize), 4);
    file.write(reinterpret_cast<const char*>(&SCREEN_WIDTH), 4);
    file.write(reinterpret_cast<const char*>(&SCREEN_HEIGHT), 4);
    file.write(reinterpret_cast<const char*>(&planes), 2);
    file.write(reinterpret_cast<const char*>(&bitDepth), 2);
    file.write(reinterpret_cast<const char*>(&compression), 4);
    file.write(reinterpret_cast<const char*>(&dataSize), 4);
    file.write(reinterpret_cast<const char*>(&horizontalResolution), 4);
    file.write(reinterpret_cast<const char*>(&verticalResolution), 4);
    file.write(reinterpret_cast<const char*>(&colors), 4);
    file.write(reinterpret_cast<const char*>(&importantColors), 4);

    // Datos de píxeles
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
//            Color pixelColor = framebuffer[(SCREEN_HEIGHT - 1 - y) * SCREEN_WIDTH + x];  // Ajuste del índice y
            Color pixelColor = framebuffer[y * SCREEN_WIDTH + x];  // Sin ajuste del índice y
            file.write(reinterpret_cast<const char*>(&pixelColor.b), 1);
            file.write(reinterpret_cast<const char*>(&pixelColor.g), 1);
            file.write(reinterpret_cast<const char*>(&pixelColor.r), 1);
        }
    }

    file.close();
}
