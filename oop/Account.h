#pragma once
#include <string>
class Account{
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;
    
protected:
    float m_balance;

public:
    Account(const std::string &name, float balance);
    ~Account();
    const std::string GetName()const;
    float getBalance()const;
    int getAccountNo()const;

    void AccumulateInterest();
    void Withdraw(float amount);
    void Deposit(float amount);
    float GetInterestRate()const;

};