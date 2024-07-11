/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:33 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 09:46:20 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

#include <cstdlib>
#include <iostream>
#include <string>

class Animal {

	public:
	Animal(void);
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual ~Animal(void);

		virtual std::string		getType(void) const;
		virtual void			makeSound(void) const;

	protected:
		std::string				_type;
};

#endif
