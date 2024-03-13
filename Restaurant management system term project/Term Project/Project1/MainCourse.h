#pragma once
#include "Food.h"
class MainCourse:public Food{
private:
static int MainCourseCount;
public:
MainCourse (string name, float price):Food (name, price)
  {type = 2;MainCourseCount++;} 
virtual int get_count (){return MainCourseCount;}
~MainCourse(){MainCourseCount--;}
virtual void decrease_count(){MainCourseCount--;};
};
int MainCourse::MainCourseCount = 0;