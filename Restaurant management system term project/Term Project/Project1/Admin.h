#pragma once
//#include <string>
//#include <fstream> 
//#include <iomanip>
//#include <vector>
//#include "Food.h"
#include "Users.h"
using namespace std;
class Admin : public User{
    
    public:
    
    Admin(string name,string password,int type) : User(name,password){type=2;};///////////////////////////////CONSTRUCTOR
    
    void Add_Dish(){////////////////////////////////////////ADD ITEM TO MENU
        float type;
        float price;
        string name;
        do{
        cout<<"Pick New Dish type."<<endl;
        cout<<"1. Appetizer"<<endl;
        cout<<"2. Main Course"<<endl;
        cout<<"3.Drink"<<endl;
        cout<<"4.Desert"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Input choice(1-5) : ";
        cin>>type;
        cin.ignore();
        if(type < 1 || type > 5 || type -(int)type != 0)
        cout<<"Please enter a valid choice (1-5).\n"<<endl;
        }while(type < 1 || type > 5 || type-(int)type  != 0);
        if(type==5){
        return;
        }
        cout<<"Enter new Dish name : ";
        getline(cin,name);
        cout<<"Enter new Dish price : $";
        cin>>price;
        cout<<"New dish '"<<name<<"' has been added."<<endl;
        UserMenu.Add_item(name,price,type);
    }

    void Remove_Dish(){////////////////////////////////////////////REMOVE ITEM FROM MENU
        int i,count,j;
        float choice;
        if(Food::itemCount !=0){
        do{
            UserMenu.display();
            cout<<"Enter no. of item to be deleted (1-"<<Food::itemCount<<") :";
            cin>>choice;
            if(choice>Food::itemCount || choice<1 || choice-(int)choice != 0){
                cout<<"Please enter a valid choice.\n"<<endl;
            }
        }while(choice>Food::itemCount || choice<1 || choice-(int)choice != 0);
        UserMenu.remove_item(choice-1);
        }
        else
        cout<<"Menu empty.\n\n"<<endl;
    }

    virtual int display_options(){///////////////////////////////////ADMIN INTERFACE
     float choice;
        do{
        cout<<"\n\n---------------Admin Interface--------------"<<endl;
        cout<<"1.Add new menu item"<<endl;
        cout<<"2.Delete a menu item"<<endl;
        cout<<"3.Add new table"<<endl;
        cout<<"4.Remove a table"<<endl;
        cout<<"5.Change Username"<<endl;
        cout<<"6.Change Password"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Input choice :";
        cin>>choice;
            if(choice<1 || choice>7 || choice - (int)choice != 0)
            cout<<"Please Enter a valid choice(1-7)\n"<<endl;
        }while(choice<1 || choice>7 || choice -(int)choice != 0);
        return choice;
        };

    void Add_Table(){//////////////////////////////////////////ADD NEW TABLE
        Table_vector.push_back(new Table);
        cout<<"Table "<<Table::table_count<<" has been added.\n"<<endl;
    }

    void Remove_Table(){/////////////////////////////////////DELETE EMPTY TABLE
        if(Table::table_count != 0){
        int availability;
        float table_no;
        for(int i=0;i<Table::table_count;i++)
        Table_vector[i]->display_tables(i);
        do{
        cout<<"\nInput table no. to be deleted(Only available tables can be deleted)(1-"<<Table::table_count<<") :";
        cin>>table_no;
        }while(table_no<1 || table_no>Table::table_count || table_no-(int)table_no != 0);
        availability=Table_vector[table_no-1]->Check_Availability();
        if(availability==1){
            delete Table_vector[table_no-1];
            Table_vector.erase(Table_vector.begin()+table_no-1);
            cout<<"Table "<<table_no<<" has been deleted.\n"<<endl;
        }
        else
        cout<<"Table is currenty in use and thus can not be deleted.\n"<<endl;
        cout<<"----------------------------------------------------------------------------------------------"<<endl;
    }
        else
        cout<<"\nNo table present"<<endl;
    }
   
};