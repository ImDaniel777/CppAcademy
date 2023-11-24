#pragma once
#include <string>
class Account{
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
private:
    std::string m_Name;
    float m_balance;
    int m_AccNo;
    static int s_ANGenerator;
};