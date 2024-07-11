/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:30:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 15:32:23 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

class ClapTrap {

	public:
	ClapTrap(); // constructeur par defaut obligatoire
	ClapTrap(std::string name); // constructeur avec param name = _Name
	ClapTrap(const ClapTrap &clap); // constructeur de recopie obligatoire
	ClapTrap &operator=(const ClapTrap &other); // operateur d'affectation obligatoire
	~ClapTrap();
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		get_Name(void);
		int				get_Hit(void);
		int				get_Energy(void);
		int				get_AttackDamage(void);

		void			set_hitPoints(int new_hit);
		void			set_energyPoints(int new_energy);
		void			set_attackDamagePoints(int new_damage);

	private:
		std::string _name;
		int			_hitPoints; // points de vie
		int			_energyPoints; // points d'energie
		int			_attackDamagePoints;
};

std::ostream &operator<<(std::ostream &stream, ClapTrap &clapTrap);

#endif
