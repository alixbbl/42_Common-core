/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:43 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 13:38:47 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define INT_MAX 100
#define INT_MIN 0

void protect_input(int& input)
{
	while (true) {

		std::cin >> input;
		if (std::cin.eof())
			exit(0);
		else if (std::cin.fail() || ((input >= INT_MAX)
				|| (input < INT_MIN))) {
			std::cout << "Invalid input ! Enter a (0-100) number :" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
		else
			break; }
}

int main()
{
	bool		continueGame = true;
	ClapTrap	ClapTrap1("KingKong");
	ClapTrap	ClapTrap2("Godzilla");
	int			input1;
	int			input2;

	std::cout	<< "Let's fight! Enter Damage points for KingKong :"
				<< std::endl;
	protect_input(input1);
	ClapTrap1.set_attackDamagePoints(input1);

	std::cout	<< "Now, enter Damage points for Godzilla :"
				<< std::endl;
	protect_input(input2);
	ClapTrap2.set_attackDamagePoints(input2);
	std::cout << std::endl;

	while (continueGame) {

		if ((ClapTrap1.get_Energy() < 1) || (ClapTrap1.get_Hit() < 1))  {
			std::cout << "Not enough energy points to attack!" << std::endl;
			break ; }
		else {
			ClapTrap1.attack(ClapTrap2.get_Name());
			ClapTrap2.takeDamage(ClapTrap1.get_AttackDamage()); }
		if (ClapTrap2.get_Hit() < 0) {
			std::cout	<< "Enter a new amount of Hit points to bring "
						<< ClapTrap2.get_Name() << " back to life !"
						<< std::endl;
			protect_input(input1);
			ClapTrap2.beRepaired(input1); }

		if (ClapTrap2.get_Energy() < 1 || ClapTrap2.get_Hit() < 1) {
			std::cout << "Not enough energy points to attack!" << std::endl;
			break ; }
		else
		{
			ClapTrap2.attack(ClapTrap1.get_Name());
			ClapTrap1.takeDamage(ClapTrap2.get_AttackDamage()); }

		if (ClapTrap1.get_Hit() < 0)
		{
			std::cout	<< ClapTrap1.get_Name() << " is DEAD !" << std::endl
						<< "Enter a new amount of Hit points to bring "
						<< ClapTrap1.get_Name() << " back to life !"
						<< std::endl;
				protect_input(input2);
				ClapTrap1.beRepaired(input2);
		}
		std::cout << std::endl;
		std::cout << ClapTrap1 << std::endl;
		std::cout << ClapTrap2 << std::endl;

		std::string continueInput;
		std::cout << "Do you want to continue? (yes/no): ";
		std::cin >> continueInput;
		if (continueInput != "yes")
			continueGame = false; }
	return 0;
}
