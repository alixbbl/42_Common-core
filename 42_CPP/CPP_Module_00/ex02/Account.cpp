/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:01:56 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/06 18:27:04 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

/******************************************************************************/
/*                         CONSTRUCTORS & DESTRUCTOR                          */
/******************************************************************************/

/* UNE STATIC est partagee par TOUTES les instances de la classe. Elles doivent
etre initialisee dans le code (avec les constructeurs pour plus de clarte):
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructeur par defaut, inutile d'init les statics
Account::Account(void) : _accountIndex(0),
                        _amount(0),
                        _nbDeposits(0),
                        _nbWithdrawals(0) {

    Account::_nbAccounts++;  // si on cree une instance le nbr de account += 1.
    return ; }

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
                        _amount(initial_deposit),
                        _nbDeposits(0),
                        _nbWithdrawals(0) {

    _displayTimestamp();
    Account::_totalAmount += initial_deposit;
    std::cout   << "index:" << this->_accountIndex
                << ";amount:" << this->_amount
                << ";created" << std::endl;
    Account::_nbAccounts++;
    return ; }

Account::~Account(void) { // destructor

    _displayTimestamp();
    std::cout   << "index:" << this->_accountIndex
                << ";amount:" << this->_amount
                << ";closed" << std::endl;
    Account::_nbAccounts++;
}

/******************************************************************************/
/*                                  GETTERS                                   */
/******************************************************************************/

int	Account::getNbAccounts( void ) {
    return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
    return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
    return (_totalNbWithdrawals);
}

/******************************************************************************/
/*                                PUBLIC FUNCTIONS                            */
/******************************************************************************/

void	Account::displayAccountsInfos( void ) {

    _displayTimestamp();
    std::cout   << "accounts:" << getNbAccounts()
                << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits()
                << ";withdrawals:" << getNbWithdrawals()
                << std::endl;
    return ;
}

void	Account::makeDeposit( int deposit ) {

    _displayTimestamp();

    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout   << "index:" << this->_accountIndex
                << ";p_amount:" << (this->_amount - deposit)
                << ";deposit:" << deposit
                << ";amount:" << this->_amount
                << ";nb_deposits:" << this->_nbDeposits << std::endl;
    return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {

    _displayTimestamp();

    if (this->_amount - withdrawal < 0) {
        std::cout   << "index:" << this->_accountIndex
                    << ";p_amount:" << this->_amount
                    << ";withdrawal:refused" << std::endl;
        return false;
    }
    else {
        std::cout   << "index:" << this->_accountIndex
                    << ";p_amount:" << this->_amount
                    << ";withdrawal:" << withdrawal
                    << ";amount:" << this->_amount
                    << ";nb_withdrawals:" << this->_nbDeposits
                    << std::endl;
        this->_nbWithdrawals++;
        this->_amount -= withdrawal;
        Account::_totalAmount += withdrawal;
	    Account::_totalNbWithdrawals++;
    }
    return true;
}

int		Account::checkAmount( void ) const {
    return (this->_amount);
}

void	Account::displayStatus( void ) const {

    _displayTimestamp();

    std::cout   << "index:" << this->_accountIndex
                << ";amount:" << this->_amount
                << ";deposits:" << this->_nbDeposits
                << ";withdrawals:" << this->_nbWithdrawals
                << std::endl;
    return ;
}

/******************************************************************************/
/*                               PRIVATE FUNCTIONS                            */
/******************************************************************************/

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "[";
    std::cout << 1900 + ltm->tm_year;
    std::cout << 1 + ltm->tm_mon;
    std::cout << ltm->tm_mday << "_";
    std::cout << ltm->tm_hour << "h";
    std::cout << ltm->tm_min << "m";
    std::cout << ltm->tm_sec << "s] ";
}
