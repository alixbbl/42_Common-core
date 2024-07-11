/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:54:23 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 11:43:05 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("Me");

		std::cout << std::endl;
		std::cout << "*-------- TEST 1 -------*" << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;
		std::cout << std::endl;
		std::cout << "*-------- TEST 2 -------*" << std::endl;
		tmp = src->createMateria("GLACE"); // Doit refuser de creer (AClass)
		me->equip(tmp); // Renvoie une erreur car Materia vide.
		std::cout << "*-------- TEST 3 -------*" << std::endl;
		ICharacter* bob = new Character("Bob");
		ICharacter* Jlo = new Character("Jlo");

		me->use(0, *bob); // utilise Ice.
		me->use(1, *bob); // utilise Cure.
		bob->use(3, *me); // ne doit rien faire (invent vide).
		Jlo->use(0, *bob); // ne doit rien faire (invent vide).

		me->unequip(0);  // supprime de l'inventory.
		me->unequip(3); // message erreur.
		me->unequip(2255); // message erreur.

		std::cout << std::endl;
		me->use(0, *bob);
		bob->use(3, *me);
		Jlo->use(1, *bob);

		delete bob;
		delete Jlo;
		delete me;
		delete src;
		return 0;
	}
}
