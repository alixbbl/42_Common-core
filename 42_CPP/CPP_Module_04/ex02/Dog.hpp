/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:10:33 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 14:47:01 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:
	Dog(void);
	Dog(const Dog &src);
	Dog &operator=(const Dog &src);
	~Dog(void);
		std::string		getType(void) const;
		void			makeSound(void) const;
		void			printIdeas(void) const;
		Brain			*getBrain(void) const;

	private:
		std::string		_type;
		Brain* 			_dogBrain;
};

#endif
