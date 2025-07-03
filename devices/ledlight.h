#pragma once
#include"../interfaces/observer.h"
#include"light.h"
#include<iostream>

class ledlight : public light , public observer {
public:
string name;
 ledlight(const std::string& name) {
        this->name = name;
    }
std::string getName() const override {
    return name;
}

int brightness = 0;
std::string status = "OFF";
std::string get_status() override;

 void update(const std::string & event) override;
 void perform_operation(std::string & op) override;

};