#pragma once
#include"../interfaces/Devices.h"
#include<vector>
#include<memory>
#include<iostream>
#include"automationmode.h"
class energysavingmode : public automationmode {
    public:
 void apply(vector<shared_ptr<devices>> devics) override;



};