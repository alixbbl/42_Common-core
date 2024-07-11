/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:01 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 15:42:21 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {

    public:
    Fixed(); // constructeur par defaut
    Fixed(const Fixed &other); // constructeur de recopie, le &other est une convention de C++
    Fixed &operator=(const Fixed &other);// operateur d'affectation, usage des references
    ~Fixed();
        int     getRawBits( void ) const; // retourne valeur du nbr a virg.fixe sans la convertir.
        void    setRawBits( int const raw ); // initialise la valeur du nbr a virgfixe depuis celle passee en param.

    private:
        int _raw_bits; // y stocker la valeur du nbr en virgule fixe.
        static const int _fract_bits = 8; // nbr de bits de la partie fractionnaire
};

/*
Le constructeur de recopie et l'operateur d'affectation sont tous les deux
utilises pour copier les donnees d'un objet existant dans un autre objet.

Faire un constructeur de recopie revient à créer un outil qui permet de créer une
NOUVELLE instance d'objet de la même classe en utilisant les données d'une instance
existante de cette classe. Cela garantit que les nouvelles instances partagent les
mêmes valeurs de données que l'instance d'origine.

L'operateur d'affectation "=", en revanche, concerne la modification d'un objet
existant. On attribue a un objet existant, les valeurs d'un autre objet.
Dans le premier cas on cree un clone, dans le second on transforme un objet
en copie d'un autre considere comme le "modele".
*/

#endif
