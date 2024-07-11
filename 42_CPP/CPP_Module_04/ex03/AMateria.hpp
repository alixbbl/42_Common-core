/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:58:03 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 11:44:00 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    public:
        AMateria(void);
        AMateria(std::string const & type); // constructeur avec argument
        AMateria(const AMateria &src); // recopie
        AMateria &operator=(const AMateria &src); // surcharge d'operateur =
        virtual ~AMateria(void);

            std::string const       &getType() const; //Returns the materia type
            virtual AMateria*       clone() const = 0;
            virtual void            use(ICharacter& target);

    protected:
            std::string             _type;
};

#endif

/*
On ajoute la classe en debut de .hpp, en effet, on a inclut "ICharacter.hpp" dans
AMateria.hpp et "AMateria.hpp" dans le header ICharacter.hpp. Cela fait que les
deux headers entrent en "dependance cyclique". Cela fout le bordel car un
header ne doit inclure QUE ce dont il a besoin pour compiler le programme, le
reste est en trop et perturbe la compilation.
On ajoute class au debut pour permettre d'eviter ce phenomene.
*/
