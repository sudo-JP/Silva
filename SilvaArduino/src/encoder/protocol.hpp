#pragma once 
#include <stdint.h>
#define MAGIC 0xBEEF 

// 12 Bytes 
struct __attribute__((packed)) Payload {
    uint16_t magic; 
    int16_t temperature; 
    int16_t humid; 
    int16_t water_level; 
    int16_t soil_moisture;
    uint16_t checksum; 
};
