#include "Account.h"

class Checking : public Account
{
    Checking(const std::string &name, float balance);
    ~Checking();
    void Withdraw(float amount);
};