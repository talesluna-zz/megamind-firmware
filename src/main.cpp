#include <Arduino.h>
#include <MegamindSensors.h>
#include <MegamindCommands.h>
#include <MegamindWireless.h>

void setup() {
  Serial.begin(115200);
  setupSensors();
  connectWireless();
}

void loop() {
  // The sound of silence...
}