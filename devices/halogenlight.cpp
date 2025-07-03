#include"halogenlight.h"

string halogenlight::get_status() {
    return "HALOGEN"+light::get_status();
}  