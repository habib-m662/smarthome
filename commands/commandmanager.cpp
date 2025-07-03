#include"command.h"
#include<stack>
#include<memory>
#include"commandmanager.h"

 void commandmanager::executecommand(std::shared_ptr<command> command){
    command->execute();
    history.push(command);
 }
 void commandmanager::undolast(){
    if(!history.empty()){
        history.top()->undo();
        history.pop();
    }
 }
