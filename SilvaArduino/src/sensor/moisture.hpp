#pragma once 
#define SOIL_MOISTURE_ANALOG_PIN 0

class SoilMoisture {
public:
    SoilMoisture();
    int get_soil_moisture();
};
