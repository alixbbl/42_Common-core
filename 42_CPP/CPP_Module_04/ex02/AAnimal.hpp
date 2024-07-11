/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:33 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 14:46:30 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AANIMAL_HPP_
# define _AANIMAL_HPP_

#include <cstdlib>
#include <iostream>
#include <string>

// RAPPEL : les constructeurs ne peuvent pas etre declares comme virtual.
// Il suffit de passer une seule methode de Animal en abstraite pour
// que toute la classe soit abstraite et non instanciable.

class AAnimal {

	public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &src);
	virtual ~AAnimal();

		virtual std::string		getType(void) const = 0; // virtuelle pure (abstrait)
		virtual void			makeSound(void) const; // (concret)

	protected:
		std::string				_type;
};

#endif

// unique difference avec le code d'avant est de mettre = 0 sur une regle de la
// classe de base, ici sur la fonction virtual makeSound. Cela rend la classe non
// instanciable. De fait on a pas besoin d'implemter les methodes virtuelles pures.
// cette classe devient "abstraite" (on met le A devant le nom de la classe.)
