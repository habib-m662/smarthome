#pragma once
#include"../interfaces/Devices.h"
#include<vector>
#include<memory>
class automationmode {
public:
virtual void apply(vector<shared_ptr<devices>> devics)=0;
virtual ~automationmode()=default;


};