#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "accountFile.h"
using namespace std;

int logInFail = 0;
int logInCheck = 0;

int logIn();
void pause(int dur);
void logInFailed();



int main() {
    char option;
    int accountNo;
    accountFile accFl;

    int logInSuccessfull =0;
    logInSuccessfull=logIn();
    system("cls");

    if(logInSuccessfull == 1){
        do {

            system("CLS");

            cout<<"\t\t\t\tBank Management System"<<endl<<endl;
            cout << "				Main Menu"<<endl;
            cout << "			1.New Account"<<endl;
            cout << "			2.Deposit" << endl;
            cout << "			3.Withdraw" << endl;
            cout << "			4.Balance" << endl;
            cout << "			5.Account Holders" << endl;
            cout << "			6.Close Account" << endl;
            cout << "			7.Modify Account" << endl;
            cout << "			8.Exit" << endl;

            cout << "			Choose Option: ";
            cout << endl << endl << endl << endl;

            cin >> option;
            system("CLS");
            switch(option) {
                case '1':
                    accFl.openAccount();
                    break;
                case '2':
                    cout << "Account No: ";
                    cin >> accountNo;
                    accFl.depositWithdraw(accountNo, 1);
                    break;
                case '3':
                    cout << "Account No: ";
                    cin >> accountNo;
                    accFl.depositWithdraw(accountNo, 2);
                    break;
                case '4':
                    cout << "Account No: ";
                    cin >> accountNo;
                    accFl.displayBalance(accountNo);
                    break;
                case '5':
                    accFl.displayUser();
                    break;
                case '6':
                    cout << "Account No: ";
                    cin >> accountNo;
                    accFl.deleteAccount(accountNo);
                    break;
                case '7':
                    cout << "Account No: ";
                    cin >> accountNo;
                    accFl.modifyAccount(accountNo);
                    break;
                case '8':
                    cout << "Thank you.." << endl;
                    break;
            }
            cin.ignore();
            cin.get();

        } while (option!='8');
    }

    return 0;
}

int logIn(){

    string userName;
    string password;
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl;
    cout<<"\t\t\t Username: ";
    getline(cin,userName);
    cout<<"\t\t\t Password: ";
    getline(cin,password);

   if(userName == "shakil" && password=="1473")
       logInCheck = 1;
   else
       logInFailed();
    return logInCheck;
}

void logInFailed(){
 logInFail++;
 if(logInFail<3){
     system("cls");
     cout<<"username or password is wrong.Try again please";
     pause(2);
     system("cls");
     logIn();
 }
 else{
     logInCheck = 2;
 }
}

void pause(int dur)
{
int temp = time(NULL) + dur;

while(temp > time(NULL));
}
