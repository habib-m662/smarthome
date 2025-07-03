#pragma once
#include"observer.h"
#include<vector>
#include<memory>
class subject {
    public:
    virtual void attach(std::shared_ptr<observer> obs)=0;
    virtual void detach(std::shared_ptr<observer> obs)=0;
    virtual void notify(const std::string & event)=0;
    virtual ~subject()=default;
};