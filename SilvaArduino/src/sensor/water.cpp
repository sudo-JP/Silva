#include "water.hpp"
#include "Arduino.h"

int WaterLevel::get_water_level() {
    return analogRead(WATER_ANALOG_PIN);
}
