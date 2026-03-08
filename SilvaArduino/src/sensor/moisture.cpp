#include "moisture.hpp"
#include "Arduino.h"

int SoilMoisture::get_soil_moisture() {
    return analogRead(SOIL_MOISTURE_ANALOG_PIN);
}
