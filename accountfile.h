#pragma once
#include "account.h"
class accountFile
{
public:
    accountFile();


    void openAccount();
    void depositWithdraw(int accountNo, int option);
    void displayBalance(int accountNo);
    void displayUser();
    void deleteAccount(int accountNo);
    void modifyAccount(int accountNo);

    ~accountFile();
};

