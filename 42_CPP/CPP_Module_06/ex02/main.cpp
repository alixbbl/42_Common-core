/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:45:29 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/18 10:10:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"

Base * generate(void) {

	// rand() permet de tirer aleatoirement entre 1, 2 et 3, la signature est
	// int random_nb_in_range = rand() % (max_value + 1 - min_value) + min_value;
	// on doit ajouter srand() pour reinitialiser rand() a chaque appel.
	srand(time(NULL));
	unsigned int i = rand() % 3 + 1;
	switch (i) {

		case 1 :
			std::cout << "New class A is created." << std::endl;
			return (new classA());
		case 2 :
			std::cout << "New class B is created." << std::endl;
			return (new classB());
		case 3 :
			std::cout << "New class C is created." << std::endl;
			return (new classC());
		default :
			return NULL;
	}
}

void identify(Base* p) {

	if (p == NULL)
		std::cout << "p is a nullptr." << std::endl;
	else if (dynamic_cast<classA*>(p))
		std::cout << "Dynamic_cast classA ok" << std::endl;
	else if (dynamic_cast<classB*>(p))
		std::cout << "Dynamic_cast classB ok" << std::endl;
	else if (dynamic_cast<classC*>(p))
		std::cout << "Dynamic_cast classC ok" << std::endl;
	else
		std::cout << "No possible identification." << std::endl;
	return ;
}

// ici les pointeurs sont interdits, on utilise donc les &.
// on utilise des 7 et non pas les classes simples car le dynamic_cast ne
// peut s'employer QUE avec des pointeurs ou des references, jamais un objet.
void identify(Base& p) {

	try {
		dynamic_cast<classA&>(p);
		std::cout << "Base p is a classA !" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "A? No, it's a : " << e.what() << std::endl; } // renverra n'importe quelle erreur de cast

	try {
		dynamic_cast<classB&>(p);
		std::cout << "Base p is a classB !" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "B? No, it's a : " << e.what() << std::endl; }

	try {
		dynamic_cast<classC&>(p);
		std::cout << "Base p is a classC !" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "C? No, it's a : " << e.what() << std::endl; }
	return ;
}


int main() {

	Base *test = generate(); // attention on malloc dans cette fonction.
	identify(test);
	identify(*test);
	delete test;
	return 0;
}
