#include "temperature.hpp"

void Temperature::begin() {
    if (!sensor.begin()) {
        Serial.println("Could not find AHT10 sensor!");
        while (1);
    }

    get_sensor_data();
}

void Temperature::get_sensor_data() {
    sensors_event_t humidEvent, tempEvent;
    sensor.getEvent(&humidEvent, &tempEvent);

    humidity = humidEvent.relative_humidity;
    temperature = tempEvent.temperature;
}

float Temperature::get_temperature() {
    return temperature;
}

float Temperature::get_humidity() {
    return humidity;
}
