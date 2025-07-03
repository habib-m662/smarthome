#pragma once
#include"../interfaces/observer.h"
#include"light.h"
#include<iostream>

class ledlight : public light , public observer {
public:
ledlight();
int brightness = 0;
std::string status = "OFF";
std::string get_status() override;

 void update(const std::string & event) override;
 void perform_operation(std::string & op) override;

};