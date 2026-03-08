#pragma once 
#include <Adafruit_AHTX0.h>


class Temperature {
public:
    Temperature();
    void begin();
    float get_humidity();
    float get_temperature();
private:
    void get_sensor_data();

    float humidity;
    float temperature;
    Adafruit_AHTX0 sensor; 
};
