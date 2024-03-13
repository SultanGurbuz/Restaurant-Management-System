#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
//#include "Users.h"
#include "Admin.h"
#include "Employee.h"
using namespace std;
class Interface{
    private :
    string FileName;
    public :
    static vector<Admin*> Admin_vec;
    static vector<Employee*> Employee_vec;
    static vector<User*> User_vec;
    static int Admin_count;
    static int Employee_count; 
    static int user_count;

    Interface(){
        if(Employee_vec.empty() && Admin_vec.empty()){
        string FullName,password;
        int type;
        cout<<"Enter File Name(Users)(has to be name.txt): ";
        cin>>FileName;
        ifstream FILE(FileName);
            while (FILE.peek () != EOF){//Fill the menu
                if(FullName == "\0")
                    FILE>>type;//get type(Drink=1,Main=2...)
                    FILE >> FullName;//get name parts
                    FILE >> password;
                if(type == 2){
                    Admin_vec.push_back(new Admin(FullName,password,type));
                    Admin_count++; 
                }
                if(type==1){
                    Employee_vec.push_back(new Employee(FullName,password,type));
                    Employee_count++;
                }
                User_vec.push_back(new Employee(FullName,password,type));
                FullName = "\0";
                password = "\0";
                type = 0;
                user_count++;
            }
        }
    }
    void welcome(){
        int choice=0;
        do{
        cout<<"---------------------WELCOME----------------------"<<endl;
        cout<<"1. EMPLOYEE LOGIN"<<endl;
        cout<<"2. ADMIN LOGIN"<<endl;
        cout<<"3. ADMIN SIGN UP"<<endl;
        cout<<"4. EMPLOYEE SIGN UP"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;
        if(choice<1 || choice>5){
            cout<<"Please Enter a valid choice.\n"<<endl;
        }
        }while(choice<1 || choice>5);
        if(choice == 5){
            return;
        }
        else if(choice == 1){
            Employee_login();
        }
        else if(choice == 2){
            Admin_login();
        }
        else if(choice==3){
            Admin_sign_up();
        }
        else if(choice ==4){
            Employee_sign_up();
        }
    }

    void Employee_sign_up(){
        string username;
        string password;
        int taken,choice=1;
        do{
            cin.get();
            taken=1;
            cout<<"Enter username(One word): ";
            getline(cin,username);
            for(int i=0;i<Admin_count || i<Employee_count;i++){
                if(i<Admin_count)
                if(username == Admin_vec[i]->get_UserName()){
                    taken=0;
                }
                if(i<Employee_count)
                if(username == Employee_vec[i]->get_UserName()){
                    taken=0;
                }
            }
            if(taken==0){
                cout<<"Username taken."<<endl;
                do{
                cout<<"Would you like to try again?"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. No"<<endl;
                cin>>choice;
                if(choice != 1 && choice != 2){
                    cout<<"Please enter a valid choice\n"<<endl;
                }
                }while(choice != 1 && choice != 2);
            }
        }while(taken != 1  && choice != 2);
        if(choice == 2){
            welcome();
        }
        if(choice == 1){
        cout<<"Enter password (one word) :";
        getline(cin,password);
        Employee_vec.push_back(new Employee(username,password,1));
        User_vec.push_back(new Employee(username,password,1));
        user_count++;
        Employee_count++;
        cout<<"Account has been created welcome "<<Employee_vec[Employee_count-1]->get_UserName()<<endl;
        EmployeeInterface(Employee_count-1);
        }
    }

    void Employee_login(){
        if(!Employee_vec.empty()){
        int choice,attempt=0,correct=0,index;
        string UserName,password;
        do{
            cin.ignore();
            cout<<"Enter UserName : ";
            getline(cin,UserName);
            cout<<"Enter password : ";
            getline(cin,password);
            cin.clear();
            index=0;
            do{
                if( UserName == Employee_vec[index]->get_UserName() && password == Employee_vec[index]->get_password()){
                    correct=1;
                }
                if(correct != 1){
                    index++;
                }
            }while(index<Employee_count && correct != 1);
            if(correct != 1){
                attempt++;
                cout<<"Password or username wrong.(remaining attempts "<<3-attempt<<")"<<endl;
            }
            if(attempt==3){
                return;
            }
            else if(attempt<3 && correct != 1){
                do{
                    cout<<"Would you like to continue?"<<endl;
                    cout<<"1. Yes"<<endl;
                    cout<<"2. No"<<endl;
                    cout<<"Enter choice : ";
                    cin>>choice;
                    if(choice != 1 && choice != 2){
                        cout<<"Please Enter a valid choice.\n"<<endl;
                        }
                    }while(choice != 1 && choice != 2);
                    if(choice == 2){
                        welcome();
                    }
            }
             if(choice == 2){
                welcome();
            }
            else if(correct==1){
                cout<<"Welcome "<<Employee_vec[index]->get_UserName()<<endl;
                EmployeeInterface(index);
            }
        }while(choice != 2 && attempt<3 && correct == 0);
        }
        else{
            cout<<"No employee present.\n\n"<<endl;
            welcome();
        }
    }

        void Admin_sign_up(){

        string username;
        string password;
        int taken,choice=1;
        do{
            cin.ignore();
            taken=1;
            cout<<"Enter username(One word): ";
            getline(cin,username);
            for(int i=0;i<Admin_count || i<Employee_count;i++){
                if(i<Admin_count)
                if(username == Admin_vec[i]->get_UserName()){
                    taken=0;
                }
                if(i<Employee_count)
                if(username == Employee_vec[i]->get_UserName()){
                    taken=0;
                }
            }
            if(taken==0){
                cout<<"Username taken."<<endl;
                do{
                cout<<"Would you like to try again?"<<endl;
                cout<<"1. Yes"<<endl;
                cout<<"2. No"<<endl;
                cin>>choice;
                if(choice != 1 && choice != 2){
                    cout<<"Please enter a valid choice\n"<<endl;
                }
                }while(choice != 1 && choice != 2);
            }
        }while(taken != 1  && choice != 2);
        if(choice == 2){
            welcome();
           }
        if(choice == 1){
        cout<<"Enter password (one word) :";
        getline(cin,password);
        Admin_vec.push_back(new Admin(username,password,2));
        User_vec.push_back(new Admin(username,password,2));
        user_count++;
        Admin_count++;
        cout<<"Account has been created welcome "<<Admin_vec[Admin_count-1]->get_UserName()<<endl;
        AdminInterface(Admin_count-1);
        }
    }

     void Admin_login(){
        if(!Admin_vec.empty()){
        int choice,attempt=0,correct=0,index;
        string UserName,password;
        do{
            cin.ignore();
            cout<<"Enter UserName : ";
            getline(cin,UserName);
            cout<<"Enter password : ";
            getline(cin,password);
            index=0;
            do{
                if( UserName == Admin_vec[index]->get_UserName() && password == Admin_vec[index]->get_password()){
                    correct=1;
                }
                if(correct != 1){
                    index++;
                }
            }while(index<Admin_count && correct != 1);
            if(correct != 1){
                attempt++;
                cout<<"Password or username wrong.(remaining attempts "<<3-attempt<<")"<<endl;
            }
            if(attempt==3){
                return;
            }
            else if(attempt<3 && correct != 1){
                do{
                    cout<<"Would you like to continue?"<<endl;
                    cout<<"1. Yes"<<endl;
                    cout<<"2. No"<<endl;
                    cout<<"Enter choice : ";
                    cin>>choice;
                    if(choice != 1 && choice != 2){
                        cout<<"Please Enter a valid choice.\n"<<endl;
                        }
                    }while(choice != 1 && choice != 2);
                    if(choice == 2){
                        welcome();
                    }
            }
            else if(correct==1){
                cout<<"Welcome "<<Admin_vec[index]->get_UserName()<<endl;
                AdminInterface(index);
            }
        }while(choice != 2 && attempt<3 && correct == 0);
        }
        else{
            cout<<"No admin present.\n\n"<<endl;
            welcome();
        }
    }

    void AdminInterface(int index){
        int choice=0;
        do{
           choice = Admin_vec[index]->display_options();
           switch(choice){
            case 1:
            Admin_vec[index]->Add_Dish();
            break;
            case 2:
            Admin_vec[index]->Remove_Dish();
            break;
            case 3:
            Admin_vec[index]->Add_Table();
            break;
            case 4:
            Admin_vec[index]->Remove_Table();
            break;
            case 5:
            Admin_vec[index]->ChangeUserName(User_vec,user_count);
            break;
            case 6:
            Admin_vec[index]->ChangePassword();
            break;
           }
        }while(choice != 7);
        welcome();
    }

    void EmployeeInterface(int index){
        int choice=0;
        do{
            choice = Employee_vec[index]->display_options();
            switch (choice)
            {
            case 1:
            Employee_vec[index]->Take_Orders();
                break;
            case 2:
            Employee_vec[index]->bring_bill();
                break;
            case 3:
            Employee_vec[index]->display_tables();
            break;
            case 4:
            Employee_vec[index]->ChangeUserName(User_vec,user_count);
            break;
            case 5:
            Employee_vec[index]->ChangePassword();
            }
        }while(choice != 6);
        welcome();
    }


    void Exit(){

        ofstream FILE(Menu::file_name);
        
          for(int i=0;i<Food::itemCount;i++){
            FILE<<Menu::MenuItems[i]->get_type()<<" "<<Menu::MenuItems[i]->get_name()<<" $"<<Menu::MenuItems[i]->get_price()<<endl;
        }
        FILE.close();
        cout<<"Menu file has been updated."<<endl;
    
        FILE.open(FileName);
        for(int i=0;i<Employee_count;i++){
            FILE<<"1 "<<Employee_vec[i]->get_UserName()<<" "<<Employee_vec[i]->get_password()<<endl;
        }
        for(int i=0;i<Admin_count;i++){
            FILE<<"2 "<<Admin_vec[i]->get_UserName()<<" "<<Admin_vec[i]->get_password()<<endl;
        }
        cout<<"User file has been updated."<<endl;
        for(int i=0;i<Employee_count;i++){
            delete Employee_vec[i];
        }
        for(int i=0;i<Admin_count;i++){
            delete Admin_vec[i];
        }
        for(int i=0;i<user_count;i++){
            delete User_vec[i];
        }
        FILE.close();
        
     } 
};

vector<Admin*> Interface::Admin_vec;

vector<Employee*> Interface::Employee_vec;

vector<User*> Interface::User_vec;

int Interface::Admin_count = 0;

int Interface::Employee_count = 0; 

int Interface::user_count = 0;
