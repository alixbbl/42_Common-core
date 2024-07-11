/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:31 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 15:19:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter {

    public:
    virtual ~ICharacter() {};

        virtual std::string const   &getName() const = 0;
        virtual void                equip(AMateria* materia) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif

/*
Il n'y aucune methode concrete dans cette interface donc on a juste un
destructeur en virtual. Pas de constructeur.
Il faut ajouter class AMateria au debut (dependance cyclique).
*/
