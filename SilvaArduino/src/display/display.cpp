#include "display.hpp"
#include "utility/Adafruit_ST7735.h"

void Display::begin() {
    screen.begin();
    clear();
}

void Display::clear() {
    screen.fillScreen(ST7735_BLACK);
}



