#include"ledlight.h"
#include<string>
#include<iostream>

 void ledlight::update(const std::string & event){
    if(event=="Motion detected"){
        string state="ON";
    ledlight::perform_operation(state);
    }
 }

    void ledlight::perform_operation(std::string& op) {
    if (op == "ON") {
        status = "ON";
    } else if (op == "OFF") {
        status = "OFF";
    } else {
        std::cout << "Invalid operation for LED Light\n";
    }
}


 

std::string ledlight::get_status() {
    return "LEDlight is " + status + " and brightness is " + std::to_string(brightness);
}