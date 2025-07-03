#pragma once
#include<iostream>
class command {
public:
virtual void execute()=0;
virtual void undo()=0;
virtual ~command()=default;



};