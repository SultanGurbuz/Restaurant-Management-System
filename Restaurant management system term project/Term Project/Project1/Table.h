#pragma once
#include <string>
#include <fstream> 
#include <iomanip>
#include <vector>
#include "Menu.h"
using namespace std;
class Table {
    private:
    vector <Food*> Orders;
    int OrderCount;
    static int Total_Earnings;
    public:
    static int table_count;
    Table(){table_count++;OrderCount=0;}
    ~Table(){
        table_count--;
    }
    int get_Order_count(){return OrderCount;}
    void display_orders(){////////////////////////////////DISPLAY ORDERS
        cout<<"----------------Orders-------------------"<<endl;
        for(int i=0;i<OrderCount;i++)
        cout<<i+1<<"."<<setw(30)<<left<<Orders[i]->get_name()<<"$"<<Orders[i]->get_price()<<endl;
    };
    float get_Total_Bill(){///////////////////////////////CLEARS TABLE + ADDS TO TOTAL EARNINGS
        int total=0;
        display_orders();
        cout<<"----------------------------------------------------"<<endl;
        for(int i=0;i<OrderCount;i++){
            total+=Orders[i]->get_price();
        }
        Orders.clear();
        OrderCount=0;
        cout<<setw(30)<<"Total : "<<"$"<<total<<endl;
         cout<<"----------------------------------------------------"<<endl;
      return total;
     }
    void Take_Orders(int item_no){
        Orders.push_back(Menu::MenuItems[item_no]);
        OrderCount++;
    }
    void display_tables(int i){//////////////////////////////////////DISPLAYS ALL TABLES + CHECKS IF THEY ARE AVAILABLE
        if(!Orders.empty()){
            cout<<"Table "<<i+1<<"."<<setw(30)<<right<<"IN USE"<<endl;
            display_orders();
        }
        else
            cout<<"Table "<<i+1<<"."<<setw(30)<<right<<"AVAILABLE"<<endl;
            cout<<"----------------------------------------------------------"<<endl;
    }

    int Check_Availability(){
        if(Orders.empty())
        return 1;
        else
        return 0;
    }
}; 