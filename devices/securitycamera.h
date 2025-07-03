#pragma once
#include"../interfaces/Devices.h"
#include<string>
class secuirtycamera : public devices {

public:
bool isrecording =0;
string name;
secuirtycamera(const std::string& name) {
    this->name = name;
}
 void perform_operation(string & op) override;
 
 string get_status() override;
std::string getName() const override {
    return name;
}
};