#include "Account.h"
#include <iostream>

int Account::s_ANGenerator = 1000;
Account::Account(const std::string &name, float balance):
m_Name(name), m_balance(balance){
    m_AccNo = ++s_ANGenerator;
}

Account::~Account(){

}

const std::string Account::GetName()const{
    return m_Name;
}

float Account::getBalance()const{
    return m_balance;
}

int Account::getAccountNo()const{
    return m_AccNo;
}

void Account::AccumulateInterest(){

}

void Account::Withdraw(float amount){
    if(amount < m_balance){
        m_balance -= amount;
    }
    else{
        std::cout<<"Insufficient balance"<<std::endl;
    }
}

void Account::Deposit(float amount){
    m_balance += amount;
}

float Account::GetInterestRate()const{
    return 0.0f;
}