/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:39 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/17 16:31:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <cstdlib>
#include <iostream>

class WrongAnimal {

	public:
	WrongAnimal(void);
	WrongAnimal(std::string type_name);
	WrongAnimal (const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	virtual ~WrongAnimal(void);

		virtual std::string getType(void) const;
		virtual void		makeSound(void) const;

	protected:
	std::string				_type;
};

#endif

/*
On ne met jamais les constructeurs en virtual car ils sont appeles avant d'initier
le polymorphisme, en revanche, si l'on veut etre surs de faire appel au bon des-
tructeur, il peut etre judicieux de les declarer en virtual dans la classe de base.


*/
