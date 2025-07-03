#pragma once
#include <string>
using std::string;
#include"../interfaces/Devices.h"
#include<iostream>
class thermostat : public devices{
public:
string mode;
double temprature;
 void perform_operation(string & op) override;
 string get_status() override;

};