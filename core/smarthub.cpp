#include"smarthub.h"
#include<memory>
#include<algorithm>

void smarthub::register_device ( string & gr ,shared_ptr<devices> device ){
    devs[gr]=device;
}
void smarthub::remove_device(string & gr){
    devs.erase(gr);
    cout<<"Device removed of Id"<<gr;
}
void smarthub::listalldevices (){
    cout<<"devices :";
    for(auto &dev:devs){
    cout<<dev.first<<" "<<dev.second->get_status();
    }

}
vector<shared_ptr<devices>> smarthub::getalldevices(){
vector<shared_ptr<devices>> all;
for(auto pair :devs){
all.push_back(pair.second);
}

return all;
}
void smarthub::applycurrentmode(){
if(currmode){
    currmode->apply(getalldevices());

}
else cout<<"No automation mode set. \n";
}
void smarthub::setautomationmode(shared_ptr<automationmode>mode){
currmode=mode;

}