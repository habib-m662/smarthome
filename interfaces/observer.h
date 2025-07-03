#pragma once
#include<string>

class observer {
public:
virtual void update(const std::string & event)=0;
virtual ~observer()=default;
};