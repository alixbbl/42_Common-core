/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:08:47 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/20 10:26:55 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_MATERIA 4 // consigne

class MateriaSource : public IMateriaSource {

    public:
    MateriaSource();
    MateriaSource(MateriaSource const &src);
    MateriaSource &operator=(MateriaSource const &src);
    ~MateriaSource();

        void                learnMateria(AMateria *materia);
        AMateria*           createMateria(std::string const &type);

    private:
        AMateria            *_materias[MAX_MATERIA];
        int                 _nb;

};

#endif
