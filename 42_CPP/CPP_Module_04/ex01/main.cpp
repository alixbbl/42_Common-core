/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:23:15 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 14:59:10 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdio>

int main()
{
	const int		packSize = 6;
	const Animal*	pack[packSize];

	for (int i = 0; i < packSize; i++) {
		if (i % 2 == 0)
			pack[i] = new Dog;
		else if (i % 2)
			pack[i] = new Cat; }
	std::cout << std::endl;
	std::cout << "Dogs and Cats are now a pack !" << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < packSize; i++) {

		std::cout << pack[i]->getType() << std::endl;
		pack[i]->makeSound();
		pack[i]->printIdeas(); // ne doit rien imprimer
	}
	for (int i = 0; i < packSize; i++)
		delete pack[i];

	std::cout << std::endl;

	const Dog* Oscar = new Dog;
	Oscar->getBrain()->addIdeas("Who's a good boy ?? ME");

	int nbIdeas = Oscar->getBrain()->getnbIdeas();
	std::cout << "Number of ideas: " << nbIdeas << std::endl;

	Oscar->getBrain()->printIdeas();

	delete Oscar;
	return 0;
}

