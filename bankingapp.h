#ifndef BANKINGAPP_H
#define BANKINGAPP_H
#include <iostream>
using namespace std;


class bankingapp
{
public:
    bankingapp();
    int chooseno();

};

class bankaccount{
protected:
    string accountID;
    double balance;
    double amountwithdraw;
    double amountdeposit;
public:
    bankaccount();
    bankaccount(double b);
    void setbalance(double b);
    double getbalanve();
    void getinfo();
    virtual double withdraw();
    virtual double diposet();

};

class Savingbankacconut:public bankaccount{
private:
    double minbalance;
public:
    Savingbankacconut();
    Savingbankacconut(double m,double b):bankaccount(b){
    minbalance=m;
    }
    double getminbal();
    void setminbal(double m);
    virtual double withdraw();
    virtual double diposet();

};

class client
{
private:
    string name;
    string address;
    string phone;
    string typeofacc;
    int  StartingBalance ;

public:
    client();
    bankaccount *ptr;
    void setinformtion();
    void setname(string n);
    void setaddress(string add);
    void setphone(string phon);
    void settypeofacc(int t);
    void setStartingBalance(int SB);
    void GetInformtion();
    string getname();
    string getaddress();
    string getphone();
    string gettype();
    int getSB();


};



#endif // BANKINGAPP_H
