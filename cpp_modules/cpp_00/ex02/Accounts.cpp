/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:30:40 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/10 20:39:01 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	this->_amount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount) std::cout << ";withdrawal:" << "refused" << std::endl;
	else
	{
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount  
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return false;
}

int		Account::checkAmount() const
{
	return this->_amount;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t	time_stamp = time(NULL);
	std::tm *lcm= localtime(&time_stamp);
	std::cout << "["
			  << (lcm->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << lcm->tm_mon + 1
			  << std::setfill('0') << std::setw(2) << lcm->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << lcm->tm_hour
			  << std::setfill('0') << std::setw(2) << lcm->tm_min
			  << std::setfill('0') << std::setw(2) << lcm->tm_sec
			  << "] ";
}

Account::Account(int initial_depo)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_depo;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_depo;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}
