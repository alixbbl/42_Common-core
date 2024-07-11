/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:40:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/16 14:17:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
/******************************* MAIN CONSIGNE ********************************/

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound(); // animal sound

/******************************* TEST PERSOS *********************************/
	std::cout << std::endl;
	const WrongAnimal* fake = new WrongAnimal();
	const WrongAnimal* mewmew = new WrongCat();

	std::cout << std::endl;
	std::cout << fake->getType() << " " << std::endl;
	std::cout << mewmew->getType() << " " << std::endl;
	fake->makeSound();  // wrong animal sound
	mewmew->makeSound();  // wrong cat sound

	std::cout << std::endl;
	delete i;
	delete j;
	delete mewmew;
	return 0;
}

/*
BUT DE L'EXERCICE :

Il s'agit d'introduire dans ce chapitre le concept de polymorphisme, qui vient
se combiner a celui d'heritage vu en 03. L'heritage permet a une classe
d'heriter des proprietes et comportements d' une classe de base. Cela permet la
reutilisation du code. Les classes derivees de la classe de base ont acces aux
membres publics ET protected de celle-ci.

La notion de polymorphisme (ici dynamique), il s'agit d'utiliser des fonctions
dites virtuelles, cad, que lorsqu'on implemente la classe de base, il est possible
de signifier quelles fonctions les classes derivees peuvent redefinir en ajoutant
virtual devant. Dans ce cas, la def de base n' est pas detruite mais completee.

FONCTION NON VIRTUAL = METHODE
*/
