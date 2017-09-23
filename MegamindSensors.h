//
// Created by tales.luna on 22/09/17.
//

#ifndef MEGAMIND_SENSORS_H
#define MEGAMIND_SENSORS_H

// Define board pins
int
        pinLights       = 5,    // LED
        pinTemperature  = A0,   // LM35
        pinLuminosity   = A1;   // LDR

// Sensors values
float temperature;

// Define I/O of sensors pins
void setupSensors() {
    pinMode(pinLights, OUTPUT);
}

/**
 * Turn ON or OFF the lights
 * @param status
 */
void onOffLights(int status) {
    digitalWrite(pinLights, status);
}

// Return value of temperature sensor
float getTemperature() {
    return (((analogRead(pinTemperature) / 1024.0) * 5000) / 10);
}

// Return value of luminosity sensor
int getLuminosity() {
    return analogRead(pinLuminosity);
}

#endif //MEGAMIND_SENSORS_H
