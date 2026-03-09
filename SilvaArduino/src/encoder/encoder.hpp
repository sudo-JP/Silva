#pragma once 
#include "protocol.hpp"
#include "CRC16.h"
#define XMODEM_INIT 0x1021, 0x0000, 0x0000, false, false
#define BYTE_SIZE 8 
#define BYTE_MASK 0xFF

class Encoder {
public: 
    Encoder() : crc(XMODEM_INIT) {};
    Payload encode(float temperature, float humid,
        int water_level, int soil_moisture); 

private: 
    CRC16 crc;
};
