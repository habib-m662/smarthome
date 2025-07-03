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
int main (){
 smarthub hub;
 auto light1= make_shared<ledlight>();
 auto thermostate= make_shared<thermostat>();
 auto camera=make_shared<secuirtycamera>();
 string l="light1";
hub.register_device(l,light1);
 string l2="thermo1";
hub.register_device(l2,thermostate);
 string l3="camera1";
hub.register_device(l3,camera);
std::cout<<"device ststus after registeration"<<"\n";
cout<<light1->get_status()<<"\n";
cout<<thermostate->get_status()<<"\n";
cout<<camera->get_status()<<"\n";
    // Apply Comfort Mode
    std::cout << "\n Applying Comfort Mode ---\n";
    hub.setautomationmode(std::make_shared<comformode>());
    hub.applycurrentmode();

    std::cout << light1->get_status() << "\n";
    std::cout << thermostate->get_status() << "\n";

    // ✅ Test Command Pattern + Undo
    commandmanager manager;
    auto lightOn = std::make_shared<turnoncommand>(light1);

    std::cout << "\n Using Command Pattern ---\n";
    manager.executecommand(lightOn);
    std::cout << light1->get_status() << "\n";

    std::cout << "\nUndo Last Command ---\n";
    manager.undolast();
    std::cout << light1->get_status() << "\n";

    // ✅ Motion Sensor triggers light
    std::cout << "\n-Motion Detected ---\n";
    auto motion = std::make_shared<motionsensor>();
    motion->attach(light1);
    motion->notify("Motion detected");
    std::cout << light1->get_status() << "\n";



    // ✅ Energy Saving Mode
    std::cout << "\n Applying Energy Saving Mode ---\n";
    hub.setautomationmode(std::make_shared<energysavingmode>());
    hub.applycurrentmode();
    std::cout << light1->get_status() << "\n";
    std::cout << thermostate->get_status() << "\n";

    return 0;
}
