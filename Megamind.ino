/**
 *  Megamind Arduino firmware
 *
 *  22/09/2017
 *  Tales Luna <tales.ferreira.luna@gmail.com>
 *
 */

#include <Arduino.h>
#include <MegamindSensors.h>
#include <MegamindCommands.h>

void setup() {
    Serial.begin(9600);
    setupSensors();
}

void loop() {
    // Aways read serial inputs
    loopCommands();
}