/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:22:46 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 14:35:47 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

Harl::Harl(void) {

    return ; }

Harl::~Harl(void){

    return ; }

/***************************** PUBLIC FUNCTIONS *******************************/


void	Harl::complain( std::string level )
{
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			index = -1;

	for ( int i = 0; i < 4; i++ )
	{
		if ( levels[i] == level )
		{
			index = i;
			break ;
		}
	}
	switch (index)
	{
		case 0:
			this->debug();
			index++;
		case 1:
			this->info();
			index++;
		case 2:
			this->warning();
			index++;
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}

/***************************** PRIVATE FUNCTIONS ******************************/

void    Harl::debug(void) {
    std::cout << "[ DEBUG ]"
            << "I love having extra bacon for my 7XL-double-cheese-triple-"
            << "pickle-specialketchup burger. I really do !" << std::endl; }

void    Harl::info(void) {
    std::cout << "[ INFO ]"
                << "I cannot believe adding extra bacon costs more money. You "
                << "didn’t put enough bacon in my burger ! If you did, "
                << "I wouldn’t be asking for more !" << std::endl; }

void    Harl::warning(void) {
    std::cout << "[ WARNING ]"
                << "I think I deserve to have some extra bacon for free. I’ve "
                << "been coming for years whereas you started working here "
                << "since last month." << std::endl; }

void    Harl::error(void) {
    std::cout << "[ ERROR ]"
                << "This is unacceptable ! I want to speak to the manager now."
                << std::endl; }
