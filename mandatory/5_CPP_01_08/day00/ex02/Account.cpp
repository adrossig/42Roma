#include "Account.hpp"

Account::Account(int initial_deposit)
{
	makeDeposit(initial_deposit);
	return;
}

Account::~Account(void)
{
	return;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _nbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _nbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	std::cout << "[" << Account::_displayTimestamp() << "]" << "index:" << _accountIndex << ";amount" << 
}