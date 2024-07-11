/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:46:16 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 15:46:59 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

/*
Le constructeur de la classe Weapon prend le nom d'une arme en argument (string),
cela permet d'initialiser l'attribut type de l'objet qui sera cree de la
classe Weapon.

La fonction getType retourne une reference constante sur string, c'est l'autre
point important de l'exercice.
*/

class Weapon {

	public:
	Weapon(); // default constructor
	Weapon(std::string weapon_name); 	// constructeur prenant une string en arg
	~Weapon();							// destructeur simple (aucune allocation)

		const std::string &getType(); // retourne une reference const sur type.
		void	setType(std::string type_of_weapon);

	private:
		std::string _type;
};

#endif
