#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include"../interfaces/Devices.h"
using namespace std ;
class light :public devices {
public:
string state;
int brightness;
light(){}
~light(){
}
 void perform_operation(string & op) override;
 
 string get_status() override;


};
