#include "Arduino.h"
#include "HardwareSerial.h"
#include "src/encoder/protocol.hpp"
#include "src/sensor/moisture.hpp"
#include "src/sensor/temperature.hpp"
#include "src/sensor/water.hpp"
#include "src/encoder/encoder.hpp"
#include <stdint.h>

#define SERIAL_BAUD_RATE 115200
#define FIVE_MINUTES 300000

SoilMoisture soil_moisture; 
WaterLevel water_level; 
Temperature temperature; 

Encoder encoder; 

void setup() {
    temperature.begin();
    Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
    float temp = temperature.get_temperature();
    float humid = temperature.get_humidity();
    int water = water_level.get_water_level();
    int soil_moist = soil_moisture.get_soil_moisture();

    const Payload payload = encoder.encode(temp, humid, water, soil_moist);
    Serial.write((const uint8_t *)&payload, sizeof(payload));

    delay(FIVE_MINUTES);
}
