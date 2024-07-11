/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:33 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:58:40 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>

class Animal {

	public:
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual ~Animal();

		virtual std::string		getType(void) const;
		virtual void			makeSound(void) const;
		virtual void			printIdeas(void)  const;

	protected:
		std::string				_type;
};

#endif
