#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std ;
class devices {
public:
std::string name;
devices(){}
~devices(){
}
virtual void perform_operation(string & op)=0;
virtual string get_status()=0;

 virtual std::string getName() const = 0;
};
