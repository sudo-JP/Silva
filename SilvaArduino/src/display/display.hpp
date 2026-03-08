#pragma once

#include <SPI.h>
#include <TFT.h>
#include <stdint.h>

// Pin setup
#define CS   10
#define DC   9
#define RST  8


// Coloring
#define CLEAR 0, 0, 0


class Display {
public:
    Display() : screen(CS, DC, RST) {};
    void begin();
    void clear();


private: 
    void background(uint8_t r, uint8_t g, uint8_t b);
    void stroke(uint8_t r, uint8_t g, uint8_t b);
    TFT screen;
};
