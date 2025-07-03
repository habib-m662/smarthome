#pragma once
#include"../interfaces/Devices.h"
#include"../interfaces/subject.h"
#include<vector>
class motionsensor : public subject , public devices {

public:
string name;
    motionsensor(const std::string& name) {
        this->name = name;
    }
vector<shared_ptr<observer>> obsvers;
void attach(shared_ptr<observer> ptr) override;
void detach(shared_ptr<observer> ptr) override;
void notify(const string & event) override ;
 void perform_operation(string & op) override;

std::string getName() const override {
        return name;
    }

 string get_status() override;


};