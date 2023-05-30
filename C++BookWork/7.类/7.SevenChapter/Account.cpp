#include "Account.h"

double Account::interestRate = initRate();
constexpr int Account::period;

Account::Account()
{
}


Account::~Account()
{
}
void Account::rate(double newRate)
{
	interestRate = newRate;
}
double Account::initRate() 
{
	return 2.0;
}