#pragma once
#include "Food.h"
class Appetizer:public Food{
private:
static int AppetizerCount;
public:
Appetizer (string name, float price):Food (name, price)
  {type = 1;AppetizerCount++;} 
virtual int get_count (){return AppetizerCount;}
~Appetizer(){AppetizerCount--;}
virtual void decrease_count(){AppetizerCount--;};
};
int Appetizer::AppetizerCount = 0;