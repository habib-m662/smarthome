#pragma once
#include <string>
using std::string;
#include"../interfaces/Devices.h"
#include<iostream>
class thermostat : public devices{
public:
string name;
string mode;
double temprature;

 thermostat(const std::string& name) {
        this->name = name;
    }


 void perform_operation(string & op) override;
 string get_status() override;
std::string getName() const override {
    return name;
}
};