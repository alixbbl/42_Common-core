/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:03:08 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 11:13:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
void    iter(T* array, int len, void (*func)(T const &)) {
    for (int i = 0; i < len; i++)
        func(array[i]);
}

template<typename T>
void    printElement(T const &element) {
    std::cout << element << std::endl;
}

template<typename T>
void printArray(T *array, int len) {
    for (int i = 0; i < len; i++)
        std::cout << array[i] << std::endl;
}

// // ajouts tests correction
// class Awesome {
//     public:
//     Awesome() : _n(42) {return ;};
//     int get_n() const {return _n;};
//     private:
//     int _n;
// };

// std::ostream &operator<<(std::ostream &o, Awesome const & src) {o << src.get_n(); return o;};

// template<typename T>
// void print(T const &x) {std::cout << x << std::endl; return; };

#endif
