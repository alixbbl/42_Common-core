/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:08:35 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 14:12:50 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() { return ;}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src): std::stack<T>(src)
{ return; }

template<typename T>
MutantStack<T>::~MutantStack() { return ; }

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &src) {

	if (this != src)
		this = std::stack<T>::operator=(src);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (this->c.end());
}
