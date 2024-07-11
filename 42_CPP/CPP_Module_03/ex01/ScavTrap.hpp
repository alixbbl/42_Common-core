/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 15:48:59 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {

	public:
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap &origin);
	ScavTrap &operator=(const ScavTrap &origin);
	~ScavTrap();

		void guardGate(void);
		void attack(std::string &target); // nouvelle fonction attack()

	private:
	ScavTrap();
};

#endif
