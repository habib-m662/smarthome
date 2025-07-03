#include<light.h>
#include<iostream>
using namespace std;
//counstructor of light class//


 //perform operation function to set operation based on the input state//
void light::perform_operation(string & op) {
    if(op=="ON"){
        light::state="ON";
        light::brightness=100;
    }
        else if(op=="OFF"){
        light::state="OFF";
        light::brightness=0;
    }
    else if(op=="DIM"){
        light::state="DIMMED ";
        string value = op.substr(4);
        int valu=stoi(value);
        if(valu>0 && valu<100){
            brightness=valu;
        }
        else{
            cout<<"invalid brightness";
        }}

    else{
        cout<<"invalid state";
    }
}


string light::get_status(){
return "light is " +state+ " and brightness is"+to_string(brightness);
}