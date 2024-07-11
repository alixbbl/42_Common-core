/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:53 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 17:03:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

    public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float floater);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
        int     getRawBits( void ) const; // mettre const ensuite indique que l'objet initial n'est pas modifie par la comparaison
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        /************** Nouvelles fonctions de surcharge *************/
        /*
        RAPPELS :

        Mettre le mot-clef const signifie que l'objet ne peut pas etre modifie. Cela peut etre une
        variable : const int x = 5; ou une fonction :
        int getValue() const {
            return value;
        } , signifie que cette fonction ne modifie pas l'objet auquel elle s'applique.

        Le mot-clef static :
        En C++, le mot "static" siginifie que la variable ou la methode (fonction), appartiennent a la
        classe plutot qu'a une instance specifique de la classe.

        On met const entre Fixed et le nom de fonction car c'est l'objet retourne qui sera constant.
        */
        static const Fixed &min(Fixed const &obj1, Fixed const &obj2);
        static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
        static Fixed &min(Fixed &obj1, Fixed &obj2);
        static Fixed &max(Fixed &obj1, Fixed &obj2);

        bool operator>(Fixed const &obj) const ;
        bool operator<(Fixed const &obj) const ;
        bool operator>=(Fixed const &obj) const ;
        bool operator<=(Fixed const &obj) const ;
        bool operator==(Fixed const &obj) const ;
        bool operator!=(Fixed const &obj) const ;

        /*
        SURCHARGE DES OPERATEURS ARITHMETIQUES - NEW
        Le type de retour est une instance de type Fixed, en copie (pas de ref &),
        Par convention, la surcharge de ces operateurs ne retourne pas de bool, et ne
        prend pas deux parametres. La logique arithmetique sera definie par la fonction
        de l'operateur.
        */
        Fixed operator+(Fixed const &obj);
        Fixed operator-(Fixed const &obj);
        Fixed operator*(Fixed const &obj);
        Fixed operator/(Fixed const &obj);

        /*
        SURCHARGE DES OPERATEURS D'INCREMENTATION ET DE DECREMENTATION - NEW
        il n'y a pas de parametre car on n'agit QUE sur un seul objet.
        Pour les deux premiers cas on a les operateurs post-incrementation et decrementation,
        dans le second en pre-inc et pre-dec. Convention d'ecriture en C++.
        */
        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

    private:
        int _raw_bits;
        static const int _fract_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
