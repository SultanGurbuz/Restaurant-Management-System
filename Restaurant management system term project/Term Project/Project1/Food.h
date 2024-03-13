#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class Food{
protected:
string name;
float price;
int type;
public:
static int itemCount;
Food (string name, float price)
  {
    this->name = name;
    this->price = price;
    //cout<<this->name<<endl;
    itemCount++;
} 
    Food(Food& copied){
    name = copied.get_name ();
    price = copied.get_price ();
    type = copied.get_type ();
 } 
  
virtual int get_count (){return itemCount;}

virtual void decrease_count() = 0;

void decrease_total (){itemCount--;} 

string get_name (){return name;}
  
float get_price (){return price;}
  
int get_type (){return type;}
void display (vector < Food * >&MenuItems)
  {
    cout << setw (30) << left << "Menu" << endl;
    for (int i = 0; i < itemCount; i++){
    cout << i +1 << "." << setw (30) << left << MenuItems[i]-> get_name() << MenuItems[i]->get_price() << "$" << endl;
    } 
} 
int display (vector <Food *>&MenuItems, int type){
int j = 0, start = 0;
cout << setw (30) << left << "Menu" << endl;
for (int i = 0; i < itemCount; i++){
if (MenuItems[i]->get_type () == type){
        cout << j +1 << "." << setw (30) << left << MenuItems[i]->get_name() << MenuItems[i]->get_price () << "$" << endl;
        j++;
        }
        if (j == 0)
        start++;}
        return start;
    }
};
int Food::itemCount = 0;
/*Menu(){
    if(MenuItems.empty()){
    string name, FullName;
    cout<<"Enter File Name(menu)(has to be name.txt): ";
    cin>>file_name;
    ifstream InputMenuFile(file_name);
    int i, j,type;
    float price, decimal;
    while (InputMenuFile.peek () != EOF){//Fill the menu
    if(FullName == "\0")
    InputMenuFile>>type;//get type(Drink=1,Main=2...)
        InputMenuFile >> name;//get name parts
        
         if (name[0] != '$' && FullName != "\0")//combine parts
            FullName = FullName + " " + name;
            
        if (FullName == "\0")//start new name
            FullName = name;
            
        else if (name[0] == '$'){//start new price calculation
            i = 1;
            price = 0;
            decimal = 0;
	    while (name[i] != '.' && name[i] != '\0'){//get normal price
	        price = price * 10 + (int) name[i] - 48;
	        i++;
                } 
        if (name[i] == '.'){//get extra digits of price
            i++;
         while (name[i] != '\0'){
            decimal = decimal * 10 + (int) name[i] - 48;
            i++;
            j++;
                } 
        while (j != 0){
            decimal /= 10;
            j--;
                }
        price += decimal;//full price
            }
        Add_item(FullName,price,type);
        FullName = "\0";
        }
    }
    }
}

void remove_item (int removed, int type){
    int i, j;
    while (i < removed) {
    if (MenuItems[removed]->get_type () == type)
    i++;
    j++;
}
    
delete MenuItems[j];
MenuItems.erase (MenuItems.begin() + j);
}
void remove_item (int removed){
delete MenuItems[removed];
MenuItems.erase(MenuItems.begin () + removed);
MenuItems[0]->decrease_total();
}
int get_totalcount(){
return Food::itemCount;
}
void display (){
MenuItems[0]->display(MenuItems);
} 
int display (int type){
return MenuItems[0]->display (MenuItems, type);
}
void display_options(){
    cout << "1.Appetizer" << endl;
    cout << "2.Main Course" << endl;
    cout << "3.Drinks" << endl;
    cout << "4.Deserts" << endl;
}
};*/


