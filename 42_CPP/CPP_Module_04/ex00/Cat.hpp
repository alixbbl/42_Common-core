/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:27 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:48:46 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {

	public:
	Cat(void);
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	~Cat(void);
		std::string		getType(void) const ;
		void			makeSound(void) const; // redefinition de makesound.

	private:
		std::string		_type;
};

#endif
