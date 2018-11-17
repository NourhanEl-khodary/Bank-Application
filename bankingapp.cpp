//Author 1: Mira Mohamed (20170305)
//Author 2: Nourhan Ihab (20170324)
//Title: Bank Application
//Date: 16/11/2018
//Version: 1.0

#include "bankingapp.h"


#include <iostream>


using namespace std;
client c1;
bankaccount b1(1500);
Savingbankacconut s1(500,1500);




//banking app {
bankingapp::bankingapp()
{
    while(true)
    {
        cout<<"welcome to banking app: "<<endl;
        cout<<"1.create a new account "<<endl;
        cout<<"2.list client informtion"<<endl;
        cout<<"3.witdrew money "<<endl;
        cout<<"4.deposite money "<<endl;

        int choice;
        cin>>choice;
        if (choice==1)
        {
            c1.setinformtion();
        }
        else if (choice==2)
        {

            c1.GetInformtion();
        }
        else if (choice==3)
        {
            c1.ptr->getinfo();
            c1.ptr->withdraw();
        }
        else if (choice==4)
        {

            c1.ptr->getinfo();
            c1.ptr->diposet();
        }
    }
}

//end of banling app





//cliebt class


client::client()
{
    name="";
    address="";
    phone="";
    typeofacc="basic";
    StartingBalance=0;
    ptr= &b1;

}

void client::setinformtion()
{
    cout<<"Enter client name: ";
    cin >>name;
    cout<<endl;
    cout<<"Enter client address: ";
    cin>>address;
    cout<<endl;
    cout<<"Enter client phone: ";
    cin >>phone;
    cout<<endl;
    cout<<"Enter client account type: "<<endl<<"1.basic."<<endl<<"2.saving type.";
    int n;
    cin >>n;
    if (n==1)
    {
        typeofacc="basic.";
        ptr= &b1;
    }
    else
    {
        typeofacc="saving type.";
        ptr= &s1;
    }
    cout<<endl;
    cout<<"Enter client starting balance: ";
    cin >> StartingBalance;
    cout<<endl;
    cout<<"An account was created with ID:FCI-015 and starting balance:"<<StartingBalance;
    cout<<endl;
}

void client::GetInformtion()
{
    cout<<"account name: "<<name<<endl;
    cout<<"account address: "<<address<<endl;
    cout<<"account phone: "<<phone<<endl;
    cout<<"account type "<<typeofacc<<endl;
    cout<<"account balance: "<<StartingBalance<<endl;
}



void client::setname(string n)
{
    name=n;
}
void client::setaddress(string add)
{
    address=add;
}
void client::setphone(string phon)
{
    phone=phon;
}
/*void client::settypeofacc(int t){
    if (t==1)return 1;
    else return 0;
}*/
void client::setStartingBalance(int SB)
{
    StartingBalance=SB;
}
string client::getname()
{
    return name;
}
string client:: getaddress()
{
    return address;
}
string client::getphone()
{
    return phone;
}
string client::gettype()
{
    return typeofacc;
}
int client::getSB()
{
    return StartingBalance;
}
//end of client





//begining of bankaccount
bankaccount::bankaccount()
{
    balance=0;
}
bankaccount::bankaccount(double b)
{
    balance=b;
}
void bankaccount:: setbalance(double b)
{
    balance=b;
}
double bankaccount::getbalanve()
{
    return balance;
}


void bankaccount::getinfo()
{
    cout<<"please enter account ID: ";
    cin>>accountID;
    cout<<"your account ID is:"<<accountID<<endl;
    cout<<"your account type is:"<<c1.gettype()<<endl;
    cout<<"your balance: "<<balance<<endl;
}



double bankaccount::withdraw()
{
    cout<<"enter the amount you want to withdraw: ";
    cin>>amountwithdraw;
    if(amountwithdraw>=balance)
    {
        cout<<"you don't have that much money...enter it once again";
        cin>>amountwithdraw;
        balance=balance-amountwithdraw;
    }
    else
    {
        balance=balance-amountwithdraw;
    }
    cout<<"thanks"<<endl;
    cout<<"your new balance is: "<< balance<<endl<<endl<<endl;
}



double bankaccount::diposet()
{
    cout<<"enter the amount you want to deposit: ";
    cin>>amountdeposit;
    balance=balance+amountdeposit;
    cout<<"thanks"<<endl;
    cout<<"your new balance is: "<< balance<<endl<<endl<<endl;
}

//end of bank account







Savingbankacconut::Savingbankacconut()
{
    minbalance=0;
}


double Savingbankacconut::getminbal()
{
    return minbalance;
}

void Savingbankacconut:: setminbal(double m)
{
    minbalance=m;
}

double Savingbankacconut ::withdraw()
{
    cout<<"enter the amount you want to withdraw: ";
    cin>>amountwithdraw;
    if(amountwithdraw>=balance-minbalance)
    {
        cout<<"you don't have that much money...enter it once again";
        cin>>amountwithdraw;
        balance=balance-amountwithdraw;
    }
    else
    {
        balance=balance-amountwithdraw;
    }
    cout<<"thanks"<<endl;
    cout<<"your new balance is: "<< balance<<endl<<endl<<endl;
}



double Savingbankacconut:: diposet(){
    cout<<"enter the amount you want to deposit: ";
    cin>>amountdeposit;
    if(amountdeposit>=100) {balance=balance+amountdeposit;}
    else {cout<<"sorry the amount is less than 100";
        cin>>amountdeposit;

    balance=balance+amountdeposit;
    }
    cout<<endl<<endl<<"thanks"<<endl;
    cout<<"your new balance is: "<< balance<<endl<<endl<<endl;

}

