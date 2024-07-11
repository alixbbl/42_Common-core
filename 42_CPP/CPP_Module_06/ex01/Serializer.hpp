/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:46:30 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/06 15:36:35 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iomanip>
# include <exception>
# include <iostream>
# include <cstdlib>
# include <stdint.h>

struct Data {

	int a;
	std::string str;
};

class Serializer {

	public:
	~Serializer();
		static uintptr_t serialize(Data* ptr); // prend un pointeur et convertit vers
		// un unsigned int pointeur.
		static Data* deserialize(uintptr_t raw); // prend un unsigned int et convertit
		// en pointeur sur Data.

	private:
	Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &src);
};

#endif
