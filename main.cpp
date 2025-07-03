#include<iostream>
#include<memory>
#include"devices/devicegroup.h"
#include"devices/thermostate.h"
#include"devices/halogenlight.h"
#include"devices/ledlight.h"
#include"devices/motionsensor.h"
#include"devices/securitycamera.h"
#include "core/smarthub.h"
#include "automation/energysavingmode.h"
#include "automation/comformode.h"
#include "commands/commandmanager.h"
#include "commands/turnoncommand.h"
using namespace std;

int main() {
    std::cout << "Smart Home Automation System Started\n\n";

    smarthub hub;

    std::cout << "Registering devices...\n";

    auto livingRoomLight = std::make_shared<ledlight>("LivingRoomLight");
    auto livingRoomThermostat = std::make_shared<thermostat>("LivingRoomThermostat");
    auto hallwaySensor = std::make_shared<motionsensor>("HallwaySensor");
    auto frontDoorCamera = std::make_shared<secuirtycamera>("FrontDoorCamera");
     std::string s="LivingRoom";
    hub.register_device(s, livingRoomLight);
    std::cout << "-> LivingRoomLight registered to group: LivingRoom\n";

    hub.register_device(s, livingRoomThermostat);
    std::cout << "-> LivingRoomThermostat registered to group: LivingRoom\n";
    std::string s3="Hallway";
    hub.register_device(s3, hallwaySensor);
    std::cout << "-> HallwaySensor registered to group: Hallway\n";
    std::string s2="Security";
    hub.register_device(s2, frontDoorCamera);
    std::cout << "-> FrontDoorCamera registered to group: Security\n";

    std::cout << "\nListing all registered devices:\n";
    for (auto& device : hub.getalldevices()) {
        std::cout << "- Device: " << device->getName() << "\n";
    }

    std::cout << "\nSetting automation mode: Comfort Mode\n";
    auto comfort = std::make_shared<comformode>();
    hub.setautomationmode(comfort);
    hub.applycurrentmode();

    std::cout << "\nSimulating motion in Hallway...\n";
    hallwaySensor->attach(livingRoomLight);  // Automatically turn on light on motion

    std::cout << "\nSending command: Turn OFF all lights in Living Room\n";
    commandmanager commandManager;
    auto turnon = std::make_shared<turnoncommand>(livingRoomLight);
    commandManager.executecommand(turnon);

    std::cout << "\nUndoing last command...\n";
    commandManager.undolast();

    std::cout << "\nSystem shutting down.\n";
    return 0;
}
