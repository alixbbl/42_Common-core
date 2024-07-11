/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:02:49 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 11:01:43 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <cstdlib>
#include <string>

template<typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T max(const T& a, const T& b) {
    if (a > b)
        return a;
    else
        return b;
}

template<typename T>
T min(const T& a, const T& b) {
    if (a < b)
        return a;
    else
        return b;
}

// class Awesome {
//     public:
//     Awesome(): _n(0) {};
//     Awesome(int n): _n(n) {};
//     Awesome &operator=(Awesome & a) { _n = a._n; return *this; };
//     bool operator==(Awesome const &src) const {return (this->_n == src._n);} ;
//     bool operator!=(Awesome const &src) const {return (this->_n != src._n);} ;
//     bool operator>(Awesome const &src) const {return (this->_n > src._n);} ;
//     bool operator<(Awesome const &src) const {return (this->_n < src._n);} ;
//     bool operator>=(Awesome const &src) const {return (this->_n >= src._n);} ;
//     bool operator<=(Awesome const &src) const {return (this->_n <= src._n);} ;
//     int get_n() const {return _n;};
//     private:
//     int _n;
// };
// std::ostream & operator<<(std::ostream &o, const Awesome &a) {o << a.get_n(); return o;};

#endif
