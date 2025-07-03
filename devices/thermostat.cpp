
#include "thermostate.h"
#include <string>
using namespace std;

void thermostat::perform_operation(string & op) {
    if (op.rfind("COOL", 0) == 0) {
        mode = "COOL";
        string value = op.substr(4);
        temprature = stod(value);
    }
    else if (op.rfind("HEAT", 0) == 0) {
        mode = "HEAT";
        string value = op.substr(4);
        temprature = stod(value);
    }
    else if (op == "OFF") {
        mode = "OFF";
        temprature = 0;
    }
    else {
        cout << "invalid mode";
    }
}


 string thermostat::get_status() {
    return "MODE is" + mode + "and temprature is"+ to_string(temprature);
 }

