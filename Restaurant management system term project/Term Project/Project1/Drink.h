#pragma once
#include "Food.h"
class Drink:public Food{
private:
static int DrinkCount;
public:
Drink (string name, float price):Food (name, price){type = 3;DrinkCount++;} 
virtual int get_count(){return DrinkCount;}
~Drink (){DrinkCount--;}
virtual void decrease_count(){DrinkCount--;};
};

int Drink::DrinkCount = 0;