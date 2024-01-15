#include "Checking.h"

Checking::Checking(const std::string &name, float balance)
    : m_Name{name}, m_balance{balance}{}

void Checking::Withdraw(float amount)
{
    if(m_balance - amount > 50)
    {
        Account::Withdraw(amount);
    }
}