#pragma once
class account
{
    int accountNo;
    char name[50];
    int balance=0;
    char type;
public:
    account();

    void createAccount();//get user data
    void showAccount();//show data
    void modifyAccount();//modify user data
    void depositMoney(int amount);//add deposited money
    void withdraw(int amount);//substract money

    void bankReport();//show data in tabular format
    int returnAccountNo();
    int returnBalance();
    char returnAccountType() { return 'S'; };

    ~account();
};

