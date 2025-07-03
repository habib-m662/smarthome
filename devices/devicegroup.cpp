#include"devicegroup.h"
#include<vector>
#include<string>

devicegroup::devicegroup(string name):name(name){}
 void devicegroup::add_device(shared_ptr<devices> dev){
device.push_back(dev);
}
void devicegroup::remove_device(shared_ptr<devices> dev){
devicegroup::device.erase(std::remove(device.begin(),device.end(),dev),device.end());
}
string devicegroup::get_status() {
    string groupname =devicegroup::name;
    string status= "Group "+ name;
    for(auto dev : device){
        status= " " + dev->get_status() + "\n";
    }
    return status;

}
void devicegroup::perform_operation(string & op){
    for(auto dev : device){
        dev->perform_operation(op);
    }
}
