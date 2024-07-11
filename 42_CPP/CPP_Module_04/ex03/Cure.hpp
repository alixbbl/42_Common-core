/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:07:36 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 11:43:35 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>

#include "AMateria.hpp"

class Cure : public AMateria {

    public:
    Cure(void);
    Cure (const Cure &src);
    Cure &operator=(const Cure &src);
    ~Cure(void);


        Cure*           clone() const;
        void            use(ICharacter& target);
};

#endif
