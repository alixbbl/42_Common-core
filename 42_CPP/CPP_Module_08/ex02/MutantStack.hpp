/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:16:47 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/24 17:14:46 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <cstdlib>
#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
    MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack &src);
    ~MutantStack();

    typedef typename std::deque<T>::iterator iterator;
	iterator	begin();
	iterator	end();
};

#include "MutantStack.tpp" // Attention a la place

#endif

/*
La classe Mutant herite de la classe stack de la STL, elle herite donc de ses
methodes et de sa particularite de ne pas avoir d'iterateur intrinseque.
On ajoute donc deux iterators en debut et fin pour bouger a l' interieur.
Pour memoire, le deque est un tableau ouvert de chaque cote.
*/
