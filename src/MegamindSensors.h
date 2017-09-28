// Created by tales.luna 22/09/2017


#ifndef MEGAMIND_SENSORS_H
#define MEGAMIND_SENSORS_H

// Define board pins
uint8_t
        pinLights       = D5,    // LED
        pinTemperature  = A0,   // LM35
        pinLuminosity   = D0;   // LDR

// Sensors values
double temperature;

// Define I/O of sensors pins
void setupSensors() {
    pinMode(pinLights, OUTPUT);
    // pinMode(pinTemperature, INPUT);
    // pinMode(pinLuminosity, INPUT);
}

/**
 * Turn ON or OFF the lights
 * @param status
 */
void onOffLights(uint8_t status) {
    digitalWrite(pinLights, status);
}

// Return value of temperature sensor
double getTemperature() {
    return (((analogRead(pinTemperature) / 1024.0) * 5000) / 10);
}

// Return value of luminosity sensor
int getLuminosity() {
    return analogRead(pinLuminosity);
}

#endif //MEGAMIND_SENSORS_H
