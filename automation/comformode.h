#include"../interfaces/Devices.h"
#include<vector>
#include<memory>
#include<iostream>
#include"automationmode.h"
class comformode : public automationmode {
    public:
 void apply(vector<shared_ptr<devices>> devs) override;



};