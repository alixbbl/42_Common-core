/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:45:12 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/18 09:54:11 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
Le but de ces fonctions est de permettre la sérialisation et la désérialisation
d'objets de type Data. La sérialisation consiste à convertir un objet, souvent
complexe, en un format (ici, un uintptr_t) qui peut être facilement stocké,
transmis ou utilisé d'une autre manière. La désérialisation est le processus
inverse, convertissant le format stocké en un objet utilisable.
*/

int main()
{
	// On cree un objet Data rempli avec deux types de donnees simples
	Data myData;
	myData.a = 42;
	myData.str = "Hello World!";

	std::cout	<< "Data.int is : " << myData.a << " and adress is : "
				<< &(myData.a) << std::endl;
	std::cout	<< "Data.str is : " << myData.str << " and adress is : "
				<< &(myData.str)  << std::endl;

	std::cout << std::endl;
	std::cout << "********************** TEST **********************" << std::endl;
	std::cout << std::endl;
	
	// On utilise serialize pour passer du format Data *au format uintptr_t
	uintptr_t serializedData = Serializer::serialize(&myData);

	// Puis on fait l'operation inverse pour revenir au format Data *
	Data * deserializedData = Serializer::deserialize(serializedData);

	// comparaison des donnees pour verifier:
	if (deserializedData != NULL) {
		std::cout	<< "Test - a : is still " << deserializedData->a
					<< &(deserializedData->a) << std::endl;
		std::cout	<< "Test - str : is still " << deserializedData->str
					<< &(deserializedData->str) << std::endl;

		std::cout	<< "Deserialization was successful!" << std::endl; }
	else
		std::cout << "Deserialization failed!" << std::endl;
	return 0;
}
