// Created by tales.luna 22/09/2017

#ifndef MEGAMIND_COMMANDS_H
#define MEGAMIND_COMMANDS_H

char luminosityStr[10], temperatureStr[10];

// Default responses for unknown commands
String unknownResponses[5] = {
        "Eu não conheço esse comando",
        "Não fui programado para responder isso",
        "Não entendi",
        "Esse comando não tem registro",
        "Seja mais específico"
};

// About me (the code)
String whoami =
        "Sou só um código programado que executa alguns comando e usa serviços de inteligência artificial do google para falar. sou meros zeros e uns";

/**
 * Return string in JSON format
 * @param response
 * @param positive
 */
String sendResponse(String response, bool positive) {

    String statusResponse = "false";

    if (positive ) {
        statusResponse = "true";
    }

    return "{\"status\": \"" + statusResponse + "\", \"message\": \"" + response  + "\"}";
}

// Execute specific command
String runCommand(String command) {

    if (command == "") {

        // No do nothing...

    } else if(command == "hello") {

        // Send hello too
        return sendResponse("Olá", true);

    } else if(command == "how_are_you") {

        // Send just this
        return sendResponse("Não sou capaz de sentir, então posso dizer que estou bem.", true);

    } else if(command == "who_are_you") {

        // Send whoami text (about the code)
        return sendResponse(whoami, true);

    } else if (command == "lights_on") {

        // Turn ON and send response
        onOffLights(HIGH);
        return sendResponse("Luzes acesas", true);


    } else if (command == "lights_off") {

        // Turn OFF lights and send response
        onOffLights(LOW);
        return sendResponse("Luzes apagadas", true);

    } else if (command == "info_temperature") {

        // Get temperature and send response
        dtostrf(getTemperature(), 4, 2, temperatureStr);
        sprintf(temperatureStr, "%s° C", temperatureStr);

        return sendResponse(temperatureStr, true);

    } else if (command == "info_luminosity") {

        //sprintf(luminosityStr, "%d", getLuminosity());
        return sendResponse(luminosityStr, true);

    } else {

        return sendResponse(unknownResponses[random(0, 4)], false);
    }

}

#endif //MEGAMIND_COMMANDS_H