#pragma once
#include "Food.h"
class Desert:public Food{
private:
static int DesertCount;
public:
Desert (string name, float price):Food (name, price){type = 4;DesertCount++;} 
virtual int get_count(){return DesertCount;}
~Desert (){DesertCount--;}
virtual void decrease_count(){DesertCount--;};
};
int Desert::DesertCount = 0;