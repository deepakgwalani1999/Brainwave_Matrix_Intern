#include <iostream>
#include <string>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<limits>
#include<cstdlib>
#include<ctime>
#include<vector>



using namespace std;
 class ATM{
   
    string searched_last_digits;
    string searched_dob;
    string searched_pin;
    string searched_name;
    float balance;
    string last_digits;
    string dob;
    string pin;
    string name;
    float file_balance;
    int transaction_count;
    fstream file;
    public:
        
        ATM(){
            
            
            cout<<"========================================="<<endl;
            cout<<"\n\n\t ATM MANAGEMENT SYSTEM \t\t\n\n\n";
            cout<<"========================================="<<endl;
          
        }
        void menu();
        void withdraw_money();
        void account_details();
        void forgot_pin();
        void savings_account();
        void userAccountRegistration();
        bool userAuthentication();
        void personalDetails();
        void transactionalDetails();
        void OTPGenerator();
        void fileUpdate();
        bool goBack();
        
        
      

 };
 //==============================WITHDRAW MONEY========================================
 void ATM::withdraw_money(){
    
    
    int choice;
    cout<<"===================================="<<endl;
    
    cout<<"\t\t1.SAVINGS ACCOUNT\t\t\n";

    cout<<"===================================="<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    cout<<endl;
    system("CLS");
    switch(choice){
        case 1:
             savings_account();
            break;
        default:
            cout<<"INVALID KEY"<<endl;
    }
  

    
 };
 //================================ACCOUNT DETAILS==========================
 void ATM::account_details(){
  
    int choice;
    cout<<"==========================================="<<endl;
    cout<<"\n\t\t1.TRANSACTION DETAILS\t\t\n";
    cout<<"\t\t 2.PERSONAL DETAILS\t\t\n";
    cout<<"==========================================="<<endl;
    cout<<"ENTER YOUR CHOICE: "<<endl;
    cin>>choice;
    system("CLS");
    switch(choice){
        case 1:
             transactionalDetails();
            break;
        case 2:
            personalDetails();
            break;
        default:
            cout<<"INVALID CHOICE"<<endl;
    }

 };
 //====================================ACCOUNT DETAILS=>PERSONAL DETAILS==========
 void ATM::personalDetails(){
    
        if(userAuthentication()){
        
                cout<<"CARD HOLDER NAME: "<<name<<endl;
                cout<<" DATE OF BIRTH "<<dob<<endl;
                cout<<"ACCOUNT (LAST-4-DIGITS): "<<last_digits<<endl;
                cout<<"BALANCE LEFT: "<<balance<<".INR"<<endl;
                cout<<"NUMBER OF TRANSACTIONS: "<<transaction_count<<endl;
        }        
            
     }

 //====================================ACCOUNT DETAILS=>TRANSACTIONAL DETAILS=====
 void ATM:: transactionalDetails(){
    file.open("Transaction.txt",ios::in);
    if(!file.is_open()){
        cout<<"FAILED TO OPEN A FILE"<<endl;
    }else{
    string line;
    
    while(!file.eof()){
        getline(file,line);
        
        cout<<line<<endl;;
    }
    file.close();
    }
    
 }
 //================================FORGOT PIN=====================================

 void ATM::forgot_pin(){
            OTPGenerator();
 }
 //======================================RANDOM OTP GENERATOR=========================
 void ATM::OTPGenerator(){
    int returned_otp;
    cout<<"ENTER THE (LAST-4-DIGITS) OF YOUR CARD: ";
    cin>>searched_last_digits;
    string file_last_digits,file_dob,file_name,file_pin,file_balance,file_transactions;

    file.open("Users.txt",ios::in);
    getline(file,file_last_digits,'*');
    getline(file,file_dob,'*');
    getline(file,file_name,'*');
    getline(file,file_pin,'*');
    getline(file,file_balance,'*');
    getline(file,file_transactions);
    file.close();

    if(searched_last_digits==file_last_digits){
        srand(static_cast<unsigned int>(time(0)));
         int otp=1000+rand()%9000;

       file.open("OTP.txt",ios::out);
       file<<"GENERATED OTP :"<<otp<<'\n';
       file.close();

       cout<<"ENTER THE OTP HERE>>>";
       cin>>returned_otp;
       if(returned_otp==otp){
        cout<<"YOUR PIN IS :"<<file_pin<<endl;
       }
       else{
        cout<<"INCORRECT OTP"<<endl;
       }


      }
      else{
         cout<<"INVALID CREDENTIALS"<<endl;
     }
     cout<<endl;

    }
 


 
//====================================MENU==========================================
 void ATM:: menu(){
    int choice;
    system("CLS");
    do{
        
    
     cout<<"\t\tMENU\t\t\n"<<endl;
     cout<<"========================================="<<endl;
     cout<<"\t\t AVAILABLE SERVICES\t\t\n";
     cout<<"1.WITHDRAW MONEY\t\t2.ACCOUNT DETAILS\t\t\n"<<endl;
     cout<<"3.FORGOT PIN\t\t\t4.EXIT\t\t\n"<<endl;
     cout<<"========================================="<<endl;
     cout<<"ENTER YOUR CHOICE: ";
     cin>>choice;
     cout<<endl;
     system("CLS");
    
     

     switch(choice){
        case 1:
             withdraw_money();
            break;
        case 2:
             account_details();
            break;
        case 3:
            forgot_pin();
            break;
        case 4:
            exit(0);
        default:
            cout<<"INVALID KEY";
     }
     
    }while(choice!=4);
 };
 void ATM::userAccountRegistration(){
    transaction_count=0;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"============================================"<<endl;
    cout<<"\n\t\t REGISTER USER\t\n\n";
    cout<<"============================================"<<endl;
    
    cout<<"ENTER YOUR CARD NUMBER (LAST 4 DIGITS): ";
    getline(cin,last_digits);
    
    cout<<"ENTER YOUR DOB: ";
    getline(cin,dob);
   
    cout<<"ENTER YOUR NAME: ";
    getline(cin,name);
   
    cout<<"ENTER YOUR PIN: ";
    getline(cin,pin);
   

    cout<<"ENTER YOUR INITIAL BALANCE: ";
    cin>>balance;
   
   

    file.open("Users.txt",ios::out);
    if(file.is_open()){
    file<<last_digits<<'*'<<dob<<'*'<<name<<'*'<<pin<<'*'<<balance<<'*'<<transaction_count<<'\n';
    file.close();
    }else{
        cout<<"UNABLE TO OPEN A FILE"<<endl;
    }
    system("CLS");
 }
 //===================================USER AUTHENTICATION================================
 bool ATM:: userAuthentication(){
    cin.ignore();
    cout<<"ENTER YOUR PIN: ";
    getline(cin,searched_pin); 

    file.open("Users.txt",ios::in);
    if(!file.is_open()){
        cout<<" ERROR IN OPENING FILE"<<endl;
        return false;
    }
    bool authenticated=false;
    string file_last_digits,file_name,file_dob,file_pin,file_balance,file_transactions;
    while(!file.eof()){
        getline(file,file_last_digits,'*');
        getline(file,file_dob,'*');
        getline(file,file_name,'*');
        getline(file,file_pin,'*');
        getline(file,file_balance,'*');
        getline(file,file_transactions);
        
        if(searched_pin==file_pin){
            cout<<"AUTHENTICATION SUCCESSFULL"<<endl;
            authenticated=true;
            balance=std::stof(file_balance);
            name=file_name;
            dob=file_dob;
            pin=file_pin;
            last_digits=file_last_digits;
            transaction_count=stoi(file_transactions);
            break;
        }

        
    }
    file.close();
    if(authenticated){
        cout<<"WELCOME "<<name<<" !!!"<<endl;
        return true;
    }
    else{
        cout<<"INVALID CREDENTIALS !!!"<<endl;
        return false;
    }
    system("CLS");
    

    }


   
    
    



  
 //=====================================WITHDRAW MONEY=>SAVINGS ACCOUNT==================

 void ATM::savings_account(){
    if(!userAuthentication()) return;
    int number_of_transactions=4;
    float minimum_amount=100;
    float money;

    
    cout<<"ENTER THE AMOUNT: ";
    cin>>money;

    
    if(money <minimum_amount){
        cout<<"AMOUNT NOT SUFFICIENT"<<endl;
        
    }
    else if(money >balance){
        cout<<"YOUR ACCOUNT HAS LESS DEPOSITS THAN YOU WANT TO WITHDRAW "<<endl;
        
    }
    else if(transaction_count>number_of_transactions){
        cout<<"NUMBER OF TRANSACTION EXCEEDED!!"<<endl;
        
    }
    else{
        
        
        balance=balance-money;
         ++transaction_count;
        cout<<"MONEY DEDUCTED!! "<<endl;
        cout<<"BALANCE LEFT :" <<balance<<"INR"<<endl;
        cout<<"NUMBER OF TRANSACTIONS DONE: "<<transaction_count<<endl;
        file.open("Transaction.txt",ios::out|ios::app);
        file<<"DEDUCTED AMOUNT: "<<money<<".INR\n"; 
        file<<"BALANCE LEFT: "<<balance<<".INR\n";
        file<<"=====================================\n";
        file.close();
       
        fileUpdate();

    
    }
    

    
    
 }


 
//=====================================UPDATE THE EXIXTING USER BALANCE IN USERS========
void ATM::fileUpdate(){
 file.open("Users.txt",ios::in);
        if(!file.is_open()){
            cout<<"FILE NOT OPENED"<<endl;
        }
         vector<string> users;
         string file_last_digits,file_dob,file_name,file_pin,file_balance,file_transactions;
         bool user_found=false;
        while(!file.eof()){
            getline(file,file_last_digits,'*');
            getline(file,file_dob,'*');
            getline(file,file_name,'*');
            getline(file,file_pin,'*');
            getline(file,file_balance,'*');
            getline(file,file_transactions);

            if(file_pin==pin){
            file_balance=to_string(balance);
            file_transactions=to_string(transaction_count);
            user_found=true;

        }
        string new_record=file_last_digits+'*'+file_dob+'*'+file_name+'*'+file_pin+'*'+file_balance+'*'+file_transactions;
        users.push_back(new_record);
        

        }
        file.close();
        if(!user_found){
            cout<<"USER NOT FOUND!!"<<endl;
            return;
        }        
        file.open("Users.txt",ios::out|file.trunc);
        for(const string user:users){
            file<<user;
        }
        file.close();
        
}
int main(){
    int choice;
    ATM atm;
    cout<<"========================================="<<endl;
    cout<<"\n\n\t\t1. REGISTER YOUR ACCOUNT\t\t\n";
    cout<<"\t\t2.  ALREADY HAVE ACCOUNT\t\t\n";
    cout<<"==========================================="<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    do{
    switch(choice){
        case 1:
            remove("Users.txt");
            remove("Transaction.txt");
            remove("OTP.txt");

            atm.userAccountRegistration();
            
        case 2:
            atm.menu();
            break;
        default:
            cout<<"INVALID CHOICE"<<endl;
    }
    }while(choice!=2);
    
     system("CLS");
    return 0;
}
