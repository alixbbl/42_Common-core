/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:16:35 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 15:25:48 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class Character : public ICharacter {

    public:
    Character(void);
    Character(std::string const name);
    Character(const Character &src); // recopie
    Character &operator=(const Character &src); // surcharge d'operateur =
    ~Character(void);

        std::string const   &getName() const;
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);

    private:
        std::string         _name;
        int                 _nbItems; // init a 0, 4 au maximum
        AMateria*           _inventory[MAX_MATERIA];
};

#endif

/*
On a une classe qui herite (ou implemente) l' interface ICharacter, donc
on ajoute : public ICharacter.
*/
