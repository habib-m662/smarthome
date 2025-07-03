#pragma once
#include"light.h"
#include<iostream>
using namespace std;
class halogenlight : public light {
public:
halogenlight(){}
string get_status()override;
};