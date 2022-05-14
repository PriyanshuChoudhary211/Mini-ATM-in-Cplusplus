#include<iostream>
#include<string>
#include<conio.h>
using namespace std;


class atm
{
    private:
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;

    public:
        //getter
        void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
        {
            account_No = account_No_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_No = mobile_No_a;
        }
        //setter 
        long int getAccount_No()
        {
            return account_No;
        }
        string getName()
        {
            return name;
        }
        int getPIN()
        {
            return PIN;
        }
        void changePin(int x)
        {
            PIN = x;
        }
        double getBalance()
        {
            return balance;
        }
        string getMobile_No()
        {
            return mobile_No;
        }

        void setMobile(string oldMobile_no, string newMobileNo)
        {
            if(oldMobile_no == mobile_No)
            {
               mobile_No = newMobileNo;
               cout<<endl<<"Sucessfully Updated "<<endl;
               getch();
            }
            else
            {
             cout<<endl<<"Your Old Mobile Number is Invalid, Please Contact to Priyanshu "<<endl;
             getch();
            }
        }
        void cashWithdraw(int amount)
        {    
         
            if(amount>0 && amount<=balance)
            {
                  balance -= amount;
                  cout<<endl<<"Collect Your Cash";
                  cout<<endl<<"Available Balance = "<<balance<<endl;
                  getch();
            }
            else
            {
                cout<<endl<<"Invalid Amount OR Insufficient Balance !!!"<<endl;
                getch();
            }            
        }
};

int main()
{
    int choice = 0,enterPIN;    
    long int enterAccountNumber;
    system("cls");

    // Make object
    atm user1;
    int a = 1234;
   user1.setData(20021907,"Priyanshu Choudhary",a,100000,"6398874675");
   do
   {  //Making First Interface
      system("cls");
      
      cout<<endl<<"****** Welcome to Priyanshu's ATM ******"<<endl;
      cout<<endl<<"Enter Your Valid Account Number: "<<endl;
      cin>>enterAccountNumber;
      cout<<endl<<"Enter Valid PIN: "<<endl;
      cin>>enterPIN;
      if(enterAccountNumber==user1.getAccount_No() && enterPIN == user1.getPIN())
      {
          do
          {
              int amount = 0;
              string oldMobileNumber, newMobileNumber;
              system("cls");

              //Second Interface
              cout<<endl<<"Welcome To ATM"<<endl;
              cout<<endl<<"Select Options"<<endl;
              cout<<endl<<"1.Check Balance"<<endl;
              cout<<endl<<"2.User Details"<<endl;
              cout<<endl<<"3.Cash Withdrawl"<<endl;
              cout<<endl<<"4.Update Mobile Number"<<endl;
              cout<<endl<<"5.To Change Pin"<<endl;
              cout<<endl<<"6.Exit"<<endl<<endl;
              cin>>choice;
              switch(choice)
              {
                  case 1:
                    cout<<endl<<"Your Bank Balance is: "<<user1.getBalance()<<endl;
                    getch();
                    break;
                  
                  case 2:
                     cout<<endl<<"User Details are:- "<<endl;
                     cout<<endl<<"Account Number:- "<<user1.getAccount_No()<<endl;
                     cout<<endl<<"Name:- "<<user1.getName()<<endl;
                     cout<<endl<<"Balance:- "<<user1.getBalance()<<endl;
                     cout<<endl<<"Mobile Number:- "<<user1.getMobile_No()<<endl;
                     getch();
                     break;
            
                  case 3:
                     cout<<endl<<"Enter Amount:- ";
                     cin>>amount;
                     user1.cashWithdraw(amount);
                     break;
                  
                  case 4:
                     cout<<endl<<"Enter Old Mobile Number: ";
                     cin>>oldMobileNumber;
                     cout<<endl<<"Enter New Mobile Number: ";
                     cin>>newMobileNumber;
                     user1.setMobile(oldMobileNumber, newMobileNumber);
                     break;

                  case 5:
                     cout<<endl<<"Enter New PIN"<<endl;
                     cin>>a;
                     user1.changePin(a);
                     cout<<"PIN Changed Successfully"<<endl;
                     break;
                   case 6:
                       exit(0);
                  default: 

                     cout<<endl<<"Enter Valid Data !!!"<<endl; 
              }

          } while (1);
          
      }
      else 
      {
          cout<<"User Details are Invalid !!! ";
          getch();
      }
   } while (1);
        
        return 0;
}