/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:10:33 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:48:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {

	public:
	Dog(void);
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog(void);
		std::string		getType(void) const;
		void			makeSound(void) const; // redefinition de makesound.

	private:
		std::string		_type;
};

#endif
