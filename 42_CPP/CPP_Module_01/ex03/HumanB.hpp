/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:45:26 by alibourb          #+#    #+#             */
/*   Updated: 2023/10/14 12:38:31 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

class HumanB {

	public:
	HumanB(std::string name);
	~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &weapon);

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif
