#include "Food.h"
#include "Drink.h"
#include "Desert.h"
#include "Appetizer.h"
#include "MainCourse.h"
#pragma once
class Menu{
public:
static vector <Food*> MenuItems;
static string file_name;
void Add_item (string name, float price, int type){	//Fill the menu vector
if (type == 1)
MenuItems.push_back (new Appetizer (name, price));
if (type == 2)
MenuItems.push_back (new MainCourse (name, price));
if (type == 3)
MenuItems.push_back (new Drink (name, price));
if (type == 4)
MenuItems.push_back (new Desert (name, price));
for (int i = 0; i < Food::itemCount; i++)
      {
for (int j = 0; j < i; j++)
    if (MenuItems[j]->get_type () > MenuItems[i]->get_type ()){
            swap (MenuItems[i], MenuItems[j]);	//For new additions to be in the right place
	    }
    }
}
Menu(){
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
if(!MenuItems.empty()){
    MenuItems[removed]->decrease_count();
    delete MenuItems[removed];
    MenuItems.erase(MenuItems.begin () + removed);
    MenuItems[0]->decrease_total();
}
else
    cout<<"no items in the menu"<<endl;
}
int get_totalcount(){
    return Food::itemCount;
}
void display (){
    MenuItems[0]->display(MenuItems);
} 
int display (int type){
    return MenuItems[0]->display(MenuItems, type);
}
void display_options(){
    cout << "1.Appetizer" << endl;
    cout << "2.Main Course" << endl;
    cout << "3.Drinks" << endl;
    cout << "4.Deserts" << endl;
}
};
string Menu::file_name;

vector <Food*> Menu::MenuItems;