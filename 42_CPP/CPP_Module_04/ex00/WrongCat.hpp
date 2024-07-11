/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:43 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:55:19 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <cstdlib>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
	WrongCat(void);
	WrongCat (const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);
	~WrongCat(void);

		std::string getType(void) const;
		void		makeSound(void) const;

	private:
	std::string		_type;
};

#endif
