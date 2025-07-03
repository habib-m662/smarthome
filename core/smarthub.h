#include"../interfaces/Devices.h"
#include<string>
#include<memory>
#include<vector>
#include"../automation/automationmode.h"
class smarthub {
public:
shared_ptr<automationmode> currmode;
unordered_map<string ,shared_ptr<devices>> devs;
void register_device ( string & gr ,shared_ptr<devices> device );
void remove_device(string & gr );
void listalldevices ();
vector<shared_ptr<devices>> getalldevices();
void setautomationmode (shared_ptr<automationmode> mode);
void applycurrentmode();
};