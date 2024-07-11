/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:37:25 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 15:51:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {

	public:
	FragTrap(std::string Name);
	FragTrap(const FragTrap &origin);
	FragTrap &operator=(const FragTrap &origin);
	~FragTrap();

		void highFivesGuys(void);

	private:
	FragTrap();
};

#endif
