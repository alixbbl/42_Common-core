/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:34:29 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 10:40:04 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

/*
Le but de l' exercice est de decouvrir les constructeurs avec arguments.

Il est demande de penser a l'interet des & et des *, ici, les & sont preferables
car un pointeur peut etre NULL, une reference non. OR il est obligatoire de
donner une Weapon a chaque Human.
Il existe un concept appele heritage de classe qui permettrait, pour cet exemple
de creer une classe Human, au dessus de HumanA et HumanB, et qui regroupe les
caracteristiques communes des deux comme : name, weapon ou encore attack.
*/

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack(); // ne doit pas avoir d'arme.
		jim.setWeapon(club);
		jim.attack(); // arme ok
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
