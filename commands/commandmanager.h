#pragma once
#include"command.h"
#include<stack>
#include<memory>
class commandmanager {
 public:
 std::stack<std::shared_ptr<command>> history;
 void executecommand(std::shared_ptr<command> command);
 void undolast();
};