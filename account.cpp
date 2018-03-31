#include "account.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;


account::account()
{
}
void account::createAccount()
{
    cout << "Account no		: ";
    cin >> accountNo;
    cout << "Account holder name	: ";
    cin.ignore();
    cin.getline(name,50);
    cout << "Account type(C/S)	: ";
    cin >> type;
    type = toupper(type);
    cout << "Initial deposition(min TK 500 for Saving and min TK1000 for current.) : ";
    cin >> balance;
    while ((type == 'S' && balance < 500) || (type == 'C' && balance < 1000))
    {
        cout << endl;
        cout << "Please deposite right amount of money (min TK 500 for Saving and min TK1000 for current.."<<endl<<endl<<"deposition: ";
        cin >> balance;

    }
    cout << "Account created successfully.";
}
void account::depositMoney(int amount)
{
    balance += amount;

}
int account::returnAccountNo()
{
    return accountNo;
}
void account::withdraw(int amount)
{
    balance-= amount;
}
int account::returnBalance()
{
    return balance;
}

void account::showAccount()
{
    cout << "Account No: " << accountNo << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Account Type: " << type << endl;
    cout << "Balance: " << balance << endl;

}
void account::bankReport() {
    cout << accountNo<<" "<<setw(10) << " " << name << setw(10) << " " << type << setw(6) << balance << endl;
}
void account::modifyAccount() {

    cout << "Account No: " << accountNo<<endl;
    cout << "Account holder name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Account Type: ";
    cin >> type;
    type = toupper(type);
    cout << "Balance: ";
    cin >> balance;
}
account::~account()
{
}
