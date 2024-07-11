/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:03:31 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 13:56:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

/* ATTENTION AUX SYNTAXES DIFFÉRENTES DES CLASSES HABITUELLES */

template<typename T>
class Array {

    public:
    Array(void) : _n(0), _array(NULL) {
        std::cout << "Default constructor called." << std::endl;
    };

    Array(unsigned int n) : _n(n) {
        std::cout << "Length constructor called." << std::endl;
        if (_n > 0)
            _array = new T[_n];
        else
            throw Array<T>::outOfRange();
    };

    Array<T>(const Array<T> &src) {
        std::cout << "Recopy operator called." << std::endl;
        this->_n = src.size();
        this->_array = new T[_n];
        for (unsigned int j = 0; j < _n; j++)
            _array[j] = src._array[j];
    };

    Array<T> &operator=(const Array<T> &src) {
        std::cout << "Assignation operator called." << std::endl;
        if (this != &src) {
            delete[] this->_array; // a voir si pas de segfault au cas ou _n = 0;
            this->_array = NULL;
            this->_n = src._n;
            _array = new T[_n];
            for (unsigned int j = 0; j < _n; j++)
                _array[j] = src._array[j];
        }
        return (*this);
    };

    ~Array(void) {
        std::cout << "Destructor called." << std::endl;
        if (_n > 0)
            delete[] _array;
        _array = NULL; }; // Rappel : gestion propre de la memoire en C++

    class outOfRange: public std::exception {
		public:
			virtual const char* what() const throw()
                { return "Index is out of range !"; }
            };

    T& operator[] (unsigned int i) const {
        if (i >= this->_n)
                throw Array<T>::outOfRange();
            return (this->_array[i]);
    }

    unsigned int size(void) const {
        return (_n); }

    void printArray(void) {
        for (unsigned int i = 0; i < this->_n; i++)
            std::cout << this->_array[i] << std::endl; }

    private:
    unsigned int    _n; // len du tableau
    T*              _array; // pointeur sur tableau créé
};


#endif
