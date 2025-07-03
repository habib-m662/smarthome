#include"motionsensor.h"
#include<algorithm>
#include<iostream>
#include<string>
void motionsensor::attach(shared_ptr<observer> ptr) {
    obsvers.push_back(ptr);
}
void motionsensor::detach(shared_ptr<observer> ptr){
    obsvers.erase(std::remove(obsvers.begin(),obsvers.end(),ptr),obsvers.end());
}
void motionsensor::notify(const string & event) {
for(auto & ob :obsvers){
    ob->update(event);
}
} 
 void motionsensor::perform_operation(string & op) {
   if(op=="detect"){
    cout<<"motion detected";
   motionsensor::notify("Motion detected");
   }
    }
 

 string motionsensor::get_status() {
    return "sensor ready";

 }


