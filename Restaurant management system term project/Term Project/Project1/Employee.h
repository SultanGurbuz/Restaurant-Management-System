#pragma once
//#include <string>
//#include <fstream> 
//#include <iomanip>
//#include <vector>
//#include "Food.h"
#include "Users.h"
using namespace std;
class Employee : public User{
    
    public :
   
   Employee(string name,string password,int type) : User(name,password){type=1;};///////////////////////////////////////////////////////////CONSTRUCTOR
    
    virtual int display_options(){//////////////////////////////////////////////////////////////////////////////////EMPLOYEE INTERFACE
        float choice;
        do{
        cout<<"\n\n---------Employee Interface---------"<<endl;
        cout<<"1.Take orders"<<endl;
        cout<<"2.Bring the bill"<<endl;
        cout<<"3.Display all tables"<<endl;
        cout<<"4.Change Username"<<endl;
        cout<<"5.Change Password"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Input choice :";
        cin>>choice;
            if(choice<1 || choice>6 || choice - (int)choice != 0)
            cout<<"Please Enter a valid choice(1-6)\n"<<endl;
        }while(choice<1 || choice>6 || choice -(int)choice != 0);
        return choice;
    };
    
    void Take_Orders(){///////////////////////////////////////////////////////////////////////////////////TAKE ORDERS
        int j,type,item_no;
        float i,choice,table_no=0;
        int count,start;
        if(Food::itemCount!=0){
        if(Table::table_count != 0){
        do{
            cout<<"Enter table no. to order(1-"<<Table::table_count<<") :";
            cin>>table_no;
        }while(table_no> Table::table_count  || table_no<1 || table_no-(int)table_no != 0);
        do{
        UserMenu.display_options();
        cout<<"What type of dish would you like to order(1-5) : ";
        cin>>i;
        if(i<1 || i>5 || i-(int)i !=0)
        cout<<"Please Enter a valid choice(1-5).\n"<<endl;
        }while(i<1 || i>5 || i-(int)i != 0);
        if(i==5){
            return;
        }

        do{
        start = UserMenu.display(i);
        if(start<Food::itemCount){
        cout<<"Enter no. of Dish you would like to order : ";
        cin>>choice;
        }
        else{
        cout<<"No item of this type in the menu.\n\n"<<endl;
        return;
        }
        }while(choice > UserMenu.MenuItems[start]->get_count()  || choice < 1 || choice - (int)choice != 0);
        Table_vector[table_no-1]->Take_Orders(choice+start-1);
        }
        else{
            cout<<"No table present."<<endl;
        }
        }
        else{
        cout<<"Menu empty.\n\n"<<endl;
        cout<<"\n\n----------------------------------------------"<<endl;
        }
    }
    
    void bring_bill(){
        if(Table::table_count != 0){
        float table_no=0;
        do{
        cout<<"Enter table no. to bring the bill (1-"<<Table::table_count<<") :";
        cin>>table_no;
        }while(table_no > Table::table_count || Table::table_count < 1  || table_no-(int)table_no != 0);
        Table_vector[table_no-1]->get_Total_Bill();
        }
        else
        cout<<"No table present"<<endl;
    }
    
    void display_tables(){
        if(Table::table_count != 0){
        int table_no,availability;
        for(int i=0;i<Table::table_count;i++)
        Table_vector[i]->display_tables(i);
        }
        else 
        cout<<"No table present"<<endl;
    }
};