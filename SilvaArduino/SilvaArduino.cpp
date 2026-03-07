#include "Arduino.h"
#include "HardwareSerial.h"
#define SERIAL_BAUD_RATE 115200

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
    byte myData[] = {0xBE, 0xEF, 0x13, 0x37};
    Serial.write(myData, sizeof(myData));
    delay(10000);
}
