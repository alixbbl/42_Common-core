/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:20:46 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/20 10:26:22 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include "AMateria.hpp"

class IMateriaSource {

    public:
    virtual ~IMateriaSource() {};

        virtual void                learnMateria(AMateria*) = 0;
        virtual AMateria*           createMateria(std::string const & type) = 0;
};

#endif

/* Interface, toutes les methodes sont virtuelles pures, elles ne seront pas
implementees ici dans un cpp mais dans les classes heritant de celle-ci.
*/
