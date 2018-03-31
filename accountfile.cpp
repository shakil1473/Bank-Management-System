#include "accountFile.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

accountFile::accountFile()
{

}


//all the funtions are used to call the function of account class
//create new account.file is opened here.

void accountFile::openAccount() {
    cout<<"\t\t\t\tBank Management System"<<endl<<endl;
    account acc;
    ofstream outFile;
    outFile.open("accountDetails.dat", ios::binary | ios::app);
    acc.createAccount();
    outFile.write(reinterpret_cast<char *> (&acc), sizeof(account));
    outFile.close();

}

//call deposit and withdraw function in account
void accountFile::depositWithdraw(int accountNo, int option) {

    cout<<"\t\t\t\tBank Management System"<<endl<<endl;
    int amount;
    bool found = false;
    account acc;
    fstream file;

    file.open("accountDetails.dat", ios::binary | ios::in|ios::out);
    if (!file) {
        cout << "some errors occured. Press any key...";
        return;
    }
    while (!file.eof() && found == false) {
        file.read(reinterpret_cast<char *>(&acc), sizeof(account));

        if (acc.returnAccountNo()== accountNo)
        {
            acc.showAccount();
            if (option == 1) {
                cout << "Deposite: TK ";
                cin >> amount;
                acc.depositMoney(amount);
            }
            if (option == 2) {
                cout << "Withdra: Tk ";
                cin >> amount;
                int balance;
                balance = acc.returnBalance()-amount;
                if ((balance < 500 && acc.returnAccountType() == 'S') || (balance < 1000 && acc.returnAccountType() == 'C'))
                    cout << "Insufficient Balance"<<endl;
                else
                    acc.withdraw(amount);
            }
            int position=(-1)*static_cast<int>(sizeof(acc));
            file.seekp(position, ios::cur);
            file.write(reinterpret_cast<char *>(&acc), sizeof(account));
            cout << "Current Balance: Tk " << acc.returnBalance() << endl;;
            found = true;
        }
    }
    file.close();
    if (found == false)
        cout << "Data not found";;

}

void accountFile::displayBalance(int accountNo) {
    cout<<"\t\t\t\tBank Management System"<<endl<<endl;
    account acc;
    bool flag = false;
    ifstream inFile;
    inFile.open("accountDetails.dat", ios::binary);
    if (!inFile)
    {
        cout << "error occured" << endl << "Press any key...." << endl;
        return;
    }
    cout << "\t\t\t\t\t\tBalance Details"<<endl<<"\t\t\t\t\t      --------------------"<<endl;

    while (inFile.read(reinterpret_cast<char *> (&acc), sizeof(account))) {
        if (acc.returnAccountNo() == accountNo) {
            acc.showAccount();
            flag = true;
        }

    }
    inFile.close();
    if (flag == false)
        cout << "Account number does not exist."<<endl;
}

void accountFile::displayUser() {

    cout<<"\t\t\t\tBank Management System"<<endl<<endl;
    account acc;
    ifstream inFile;
    inFile.open("accountDetails.dat", ios::binary);
    if (!inFile) {
        cout << "error occurred" << endl << "Press any key..." << endl;
        return;
    }
    cout << "Account Holder List" << endl;
    cout << "A/C No.             Name               Type                 Balance" << endl;
    while (inFile.read(reinterpret_cast<char *> (&acc), sizeof(account))) {
        acc.bankReport();
    }
    inFile.close();
}
void accountFile::deleteAccount(int accountNo)
{
    cout<<"\t\t\t\tBank Management System"<<endl<<endl;
    account acc;
    ifstream inFile;
    ofstream outFile;

    inFile.open("accountDetails.dat", ios::binary);

    if (!inFile) {
        cout << "error occured.." << endl << "Press any key..." << endl;
        return;
    }

    outFile.open("temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);

    while (inFile.read(reinterpret_cast<char *> (&acc), sizeof(account))) {
        if (acc.returnAccountNo() != accountNo) {
            outFile.write(reinterpret_cast<char *> (&acc), sizeof(account));
        }
    }

    inFile.close();
    outFile.close();

    remove("accountDetails.dat");
    rename("temp.dat", "accountDetails.dat");

    cout << "Deleted..." << endl;

}

void accountFile::modifyAccount(int accountNo) {

    cout<<"\t\t\t\tBank Management System"<<endl<<endl;

    bool found = false;

    account acc;
    fstream file;

    file.open("accountDetails.dat", ios::binary | ios::in | ios::out);

    if (!file) {
        cout << "error occured.." << endl;
        return;
    }

    while (!file.eof() && found == false) {

        file.read(reinterpret_cast<char *> (&acc), sizeof(account));

        if (acc.returnAccountNo() == accountNo) {
            system("CLS");
            cout << "Present Details.." << endl<<endl;
            acc.showAccount();
            cout << endl << endl;
            cout << "New Details Please..." << endl<<endl;
            acc.modifyAccount();
            int position = (-1)*static_cast<int>(sizeof(account));
            file.seekp(position, ios::cur);
            file.write(reinterpret_cast<char *> (&acc), sizeof(account));
            cout << "Record updated...";
            found = true;
        }
    }
    file.close();
    if (found == false)
        cout << "Data not found..." << endl;
}


accountFile::~accountFile()
{

}
