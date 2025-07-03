#pragma once
#include"../interfaces/Devices.h"
#include<string>
class secuirtycamera : public devices {

public:
bool isrecording =0;

 void perform_operation(string & op) override;
 
 string get_status() override;

};