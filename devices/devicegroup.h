#pragma once
#include<iostream>
#include"../interfaces/Devices.h"
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;
class devicegroup : public devices {
public:
string name;
devicegroup();
devicegroup(string name);
vector<shared_ptr<devices>> device;

void add_device(shared_ptr<devices> dev);
void remove_device(shared_ptr<devices> dev);
 void perform_operation(string & op) override;
 string get_status() override;
};