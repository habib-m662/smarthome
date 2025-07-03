#include"../interfaces/Devices.h"
#include<vector>
#include<memory>
#include<iostream>
#include"energysavingmode.h"

 void energysavingmode::apply(vector<shared_ptr<devices>> devics){
    cout<<"applying energy saving mode ";
    for(auto dev :devics){
        string state="OFF";
        dev->perform_operation(state);
    }
 }



