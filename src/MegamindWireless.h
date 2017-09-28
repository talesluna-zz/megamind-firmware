// Created by tales.luna 28/09/2017


#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#ifndef MEGAMIND_ARDUINO_FIRMWARE_WIRELESS_H
#define MEGAMIND_ARDUINO_FIRMWARE_WIRELESS_H

#define SERVER_PORT 2110

char SSID[] = "NAME_WIFI";
char PASS[] = "PASS_WIFI";

// Check wireless connection status
bool checkWireless() {

    Serial.println();

    if(WiFi.status() == WL_CONNECTED){
        Serial.println("status: connected");
        Serial.print("ip: ");
        Serial.println(WiFi.localIP());
        return true;
    }
    else{
        Serial.println("status: not_connected");
        return false;
    }
}

// Create TCP Server for receive commands
void createServer() {

    WiFiServer server(SERVER_PORT);
    server.begin();

    while (true) {
        WiFiClient client = server.available();

        if (client) {
            while (client.connected()) {
                String command = client.readStringUntil('\n');
                if (command != "") {
                    client.println(runCommand(command));
                    client.stop();
                }
            }
        }
    }
}

// Connect to wireless network
void connectWireless() {

    WiFi.begin(SSID, PASS);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("=");
    }

    // Check connection
    if(checkWireless()) {
        createServer();
    }
}

#endif //MEGAMIND_ARDUINO_FIRMWARE_WIRELESS_H

