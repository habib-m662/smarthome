
#include"../interfaces/Devices.h"
#include<vector>
#include<memory>
#include<iostream>
#include"comformode.h"
#include "securitycamera.h"
#include "ledlight.h"
#include "thermostate.h"
void comformode::apply(std::vector<std::shared_ptr<devices>> devs) {
    std::cout << "applying Comfort Mode";

    for (auto& device : devs) {
        if (auto cam = std::dynamic_pointer_cast<secuirtycamera>(device)) {
            std::string command = "ON"; // Or whatever temp
            cam->perform_operation(command);
        } else if (auto led = std::dynamic_pointer_cast<ledlight>(device)) {
            std::string command = "ON"; // Or whatever temp
            led->perform_operation(command);
        } else if (auto thermo = std::dynamic_pointer_cast<thermostat>(device)) {
            std::string command = "HEAT25"; // Or whatever temp
            thermo->perform_operation(command);
        }
    }
}




