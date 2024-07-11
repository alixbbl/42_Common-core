/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:09:27 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 13:59:12 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	public:
	Cat(void);
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	~Cat(void);
		std::string		getType(void) const ;
		void			makeSound(void) const;
		void			printIdeas(void) const;
		Brain			*getBrain(void) const;

	private:
		std::string		_type;
		Brain*			_catBrain;
};

#endif
