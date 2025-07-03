#include"command.h"
#include<memory>
#include"turnoncommand.h"
#include"../interfaces/Devices.h"

void turnoncommand::execute(){
        string state="ON";
turnoncommand::devic->perform_operation(state);
}
void turnoncommand::undo() {
        string state="OFF";
turnoncommand::devic->perform_operation(state);
}
turnoncommand::turnoncommand(std::shared_ptr<devices> dev) : devic(dev){}
