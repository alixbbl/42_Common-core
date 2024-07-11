/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:53:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/06 14:23:04 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

Serializer::Serializer() {
	return ;
}

Serializer::~Serializer() {
	return ;
}

Serializer::Serializer(Serializer const &src) {
	*this = src;
}

Serializer &Serializer::operator=(Serializer const &src) {
	(void)src;
	return (*this);
}

/***************************** PUBLIC FUNCTIONS *******************************/

uintptr_t Serializer::serialize(Data* ptr) {

	uintptr_t cooked = reinterpret_cast<uintptr_t>(ptr);
	return cooked;
}

Data* Serializer::deserialize(uintptr_t raw) {

	Data * cooked = reinterpret_cast<Data *>(raw);
	return (cooked);
}
