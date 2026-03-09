#include "encoder.hpp"

Payload Encoder::encode(float temperature, float humid,
        int water_level, int soil_moisture) {
    crc.restart();
    Payload p;  

    // MAGIC 
    p.magic = MAGIC; 
    crc.add(MAGIC & BYTE_MASK);
    crc.add(MAGIC >> BYTE_SIZE);

    // float only keeps two decimal, so mult by 100 
    // to convert to int, then let backend handles / 100 
    // TEMPERATURE 
    int16_t temp16 = static_cast<int16_t>(temperature * 100);
    p.temperature = temp16;
    crc.add(temp16 & BYTE_MASK);
    crc.add(temp16 >> BYTE_SIZE);

    // HUMIDITY
    int16_t humid16 = static_cast<int16_t>(humid * 100);
    p.humid = humid16;
    crc.add(humid16 & BYTE_MASK);
    crc.add(humid16 >> BYTE_SIZE);

    // WATER LEVEL 
    int16_t water16 = static_cast<int16_t>(water_level);
    p.water_level = water16; 
    crc.add(water16 & BYTE_MASK);
    crc.add(water16 >> BYTE_SIZE);

    // SOIL MOISTURE 
    int16_t soil16 = static_cast<int16_t>(soil_moisture);
    p.soil_moisture = soil16;
    crc.add(soil16 & BYTE_MASK);
    crc.add(soil16 >> BYTE_SIZE);

    p.checksum = crc.calc();
    return p; 
}
