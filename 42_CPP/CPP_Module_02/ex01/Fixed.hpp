/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 16:20:01 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

    public:
    Fixed(void);
    Fixed(const int integer); // constructeur sur entier constant
    Fixed(const float floater); // constructeur sur float constant
    Fixed(const Fixed &other); // constructeur de recopie
    Fixed &operator=(const Fixed &other);// operateur d'affectation
    ~Fixed();

        int     getRawBits( void ) const; // retourne valeur du nbr a virg.fixe sans la convertir.
        void    setRawBits( int const raw ); // initialise la valeur du nbr a virgfixe depuis celle passee en param.
        float   toFloat( void ) const;
        int     toInt( void ) const;

    private:
        int _raw_bits; // y stocker la valeur du nbr en virgule fixe.
        static const int _fract_bits = 8; // nbr de bits de la partie fractionnaire
};

std::ostream &operator<<( std::ostream &outstream, const Fixed &fixed );

/* signifie : l'operateur "<<" appartenant a la bibli ostream de std,
est redefini (ou surcharge) et prend la signification du contenu de ().
on fait pareil au dessus pour l'operateur "=" */

/* Le constructeur de recopie et l'operateur d'affectation sont tous les deux
utilises pour copier les donnees d'un objet existant dans un autre objet.

Faire un constructeur de recopie revient à créer un outil qui permet de créer une
NOUVELLE instance d'objet de la même classe en utilisant les données d'une instance
existante de cette classe. Cela garantit que les nouvelles instances partagent les
mêmes valeurs de données que l'instance d'origine.

L'operateur d'affectation, en revanche, concerne la modification d'un objet
existant. On attribue a un objet existant, les valeurs dún autre objet.
Dans le premier cas on cree un clone, dans le second on transforme un objet
en copie d'un autre considere comme le "modele".

*/

#endif
