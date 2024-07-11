/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:06:30 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 15:12:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>

#include "AMateria.hpp"

class Ice : public AMateria {

    public:
    Ice(void);
    Ice(const Ice &src);
    Ice &operator=(const Ice &src);
    ~Ice(void);

        Ice*            clone() const;
        void            use(ICharacter& target);
};

#endif

/* Ice herite de la classe abstraite AMateria, attention a modifier les const. */
