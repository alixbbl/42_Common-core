/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/21 16:44:03 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

class ClapTrap {

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clap);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap(); // destructeur obligatoire
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string get_Name(void);
		int		get_Hit(void);
		int		get_Energy(void);
		int		get_AttackDamage(void);

		void	set_hitPoints(int new_hit);
		void	set_energyPoints(int new_energy);
		void	set_attackDamagePoints(int new_damage);

	protected:
		std::string _Name;
		int			_hitPoints; // points de vie
		int			_energyPoints; // points d'energie
		int			_attackDamagePoints;
};

std::ostream &operator<<(std::ostream &stream, ClapTrap &clapTrap);

#endif

// on fait passer les data private en "protected" afin de pouvoir
// les utiliser dans le cas de l' heritage.
