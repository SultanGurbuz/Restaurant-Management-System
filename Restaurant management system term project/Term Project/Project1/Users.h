#pragma once
#include <string>
#include <fstream> 
#include <iomanip>
#include <vector>
//#include "Food.h"
#include "Table.h"
#include "Menu.h"
using namespace std;
class interface;
/*class Table {
    private:
    vector <Food*> Orders;
    int OrderCount=0;
    static int Total_Earnings;
    public:
    static int table_count;
    Table(){table_count++;}
    ~Table(){
        table_count--;
    }
    int get_Order_count(){return OrderCount;}
    void display_orders(){////////////////////////////////DISPLAY ORDERS
        cout<<"----------------Orders-------------------"<<endl;
        for(int i=0;i<OrderCount;i++)
        cout<<i+1<<"."<<setw(30)<<left<<Orders[i]->get_name()<<"$"<<Orders[i]->get_price()<<endl;
    };
    int get_Total_Bill(){///////////////////////////////CLEARS TABLE + ADDS TO TOTAL EARNINGS
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
}; */
class User {
    protected:
    static int UserCount;
    string UserName;
    string password;
    int type;
    public:
    static Menu UserMenu;
    static vector <Table*> Table_vector;
    User(string name,string password){UserName=name;this->password=password;UserCount++;}///////////////////////////////CONSTRUCTOR
    string get_UserName(){return UserName;}
    string get_password(){return password;}
    void set_UserName(string name){UserName=name;}
    int get_type(){return type;}
    void ChangePassword(){///////////////////////////////////////////////////////////CHANGE PASSWORD(EMPLOYEE + ADMIN)
        string NewPassword,PasswordCheck;
        int i=0,choice=0;
        do{
            cin.get();
            cout<<"Input old password : ";
            getline(cin,PasswordCheck);
            if(password==PasswordCheck)
            i=1;
            else{
            cout<<"Password incorrect.would you like to try again?\n"<<endl;
            do{cout<<"1. Yes"<<endl;
            cout<<"2. No"<<endl;
            cout<<"Choice : ";
            cin>>choice;
            if(choice != 1 && choice != 2 && choice % 1 != 0)
                cout<<"Please enter a  valid choice(1-2)"<<endl;
            }while(choice != 1 && choice != 2 && choice % 1 != 0);}
        }while(i != 1 && choice != 2);
        if(i==1){
            choice=0;
            cout<<"Input new password : ";
            getline(cin,NewPassword);
            cout<<"Are you sure you want to change your password?\n";
                do{ cout<<"1. Yes"<<endl;
                    cout<<"2. No"<<endl;
                    cin>>choice;
                    if(choice != 1 && choice != 2 && choice % 1 != 0)
                    cout<<"Please enter a  valid choice(1-2)"<<endl;
                        }while(choice != 1 && choice != 2 && choice % 1 != 0);
        }
        if(choice==1){
            password=NewPassword;
            cout<<"Password has been successfully changed.\n\n"<<endl;
        }
    }
    void ChangeUserName(vector <User*> User_vec,const int user_count){///////////////////////////////////////////////////////////CHANGE USERNAME(EMPLOYEE + ADMIN)
        string username;
        string password;
        int spot,taken;
        float choice=1;
            do{
            cin.ignore();
            taken=1;  
            cout<<"Enter new username(One word): ";
            getline(cin,username);
            for(int i=0;i<user_count;i++){
                if(username==User_vec[i]->get_UserName())
                taken=0;
            }
            if(taken==0){
                cout<<"\n\n"<<endl;
            do{cout<<"Username taken.would you like to try again?\n"<<endl;
            cout<<"1. Yes"<<endl;
            cout<<"2. No"<<endl;
            cout<<"Choice : ";
            cin>>choice;
            if(choice != 1 && choice != 2)
                cout<<"Please enter a  valid choice(1-2)"<<endl;
            }while(choice != 1  && choice != 2 );
            }
            }while(taken != 1 && choice != 2);
            if(taken==1){
            for(int i=0;i<user_count;i++){
                if(User_vec[i]->get_UserName()==UserName)
                spot=i;
            }
            User_vec[spot]->set_UserName(username);
            UserName=username;
            //cout<<UserName;
            cout<<"Username has been successfully changed.\n-------------------------------------------------"<<endl;
            }
            else if(choice==2){
                cout<<"\n\n-------------------------------------------------------"<<endl;
            }
    }
    
};

/*class Employee : public User{
    
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
        int i,j,type,item_no;
        int table_no=0,count,start,choice=0;
        if(Table::table_count != 0){
        do{
            cout<<"Enter table no. to order(1-"<<Table::table_count<<") :";
            cin>>table_no;
            //TODO: FIX THIS
        }while(table_no> Table::table_count|| table_no<=0);
        do{
        UserMenu.display_options();
        cout<<"What type of dish would you like to order(1-5) : ";
        cin>>i;
        if(i<1 || i>5)
        cout<<"Please Enter a valid choice(1-5).\n"<<endl;
        }while(i<1 || i>5);
        if(i==5){
            return;
        }
        do{
        start = UserMenu.display(i);
        cout<<"Enter no. of Dish you would like to order : ";
        cin>>choice;
        }while(choice > UserMenu.MenuItems[start]->get_count() || choice <= 0);
        Table_vector[table_no-1]->Take_Orders(choice+start-1);
        }
        else{
            cout<<"No table present."<<endl;
        }
        cout<<"\n\n----------------------------------------------"<<endl;
    }
    
    void bring_bill(){
        if(Table::table_count != 0){
        int table_no=0;
        do{
        cout<<"Enter table no. to bring the bill (1-"<<Table::table_count<<") :";
        cin>>table_no;
        }while(table_no > Table::table_count || Table::table_count < 1);
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
};*/

 /* class Admin : public User{
    
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
        int i,count,j,choice;
        do{
            UserMenu.display();
            cout<<"Enter no. of item to be deleted (1-"<<Food::itemCount<<") :";
            cin>>choice;
            if(choice>Food::itemCount || choice<1){
                cout<<"Please enter a valid choice.\n"<<endl;
            }
        }while(choice>Food::itemCount || choice<1);
        UserMenu.remove_item(choice-1);
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
        int table_no,availability;
        for(int i=0;i<Table::table_count;i++)
        Table_vector[i]->display_tables(i);
        do{
        cout<<"\nInput table no. to be deleted(Only available tables can be deleted)(1-"<<Table::table_count<<") :";
        cin>>table_no;
        }while(table_no<1 || table_no>Table::table_count);
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
   
};*/

Menu User::UserMenu;

int User::UserCount=0;

int Table::Total_Earnings=0;

vector <Table*> User::Table_vector;

int Table::table_count=0;

/*class Interface{
    private :
    string FileName;
    public :
    static vector<Admin*> Admin_vec;
    static vector<Employee*> Employee_vec;
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
                cin.ignore();
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
        Employee_count++;
        cout<<"Account has been created welcome "<<Employee_vec[Employee_count-1]->get_UserName()<<endl;
        EmployeeInterface(Employee_count-1);
        }
    }

    void Employee_login(){
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
        Admin_vec.push_back(new Admin(username,password,1));
        Admin_count++;
        cout<<"Account has been created welcome "<<Admin_vec[Admin_count-1]->get_UserName()<<endl;
        AdminInterface(Admin_count-1);
        }
    }

     void Admin_login(){
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
            Admin_vec[index]->ChangeUserName();
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
            Employee_vec[index]->ChangeUserName();
            break;
            case 5:
            Employee_vec[index]->ChangePassword();
            }
        }while(choice != 6);
        welcome();
    }

    void Exit(){
        ofstream FILE(FileName);
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

        FILE.close();
        FILE.open(Menu::file_name);
        for(int i=0;i<Food::itemCount;i++){
            FILE<<Menu::MenuItems[i]->get_type()<<" "<<Menu::MenuItems[i]->get_name()<<" $"<<Menu::MenuItems[i]->get_price()<<endl;
        }
        FILE.close();
        cout<<"Menu file has been updated."<<endl;
    }

};

vector<Admin*> Interface::Admin_vec;

vector<Employee*> Interface::Employee_vec;

int Interface::Admin_count=0;

int Interface::Employee_count=0; 

int Interface::user_count = 0;*/

