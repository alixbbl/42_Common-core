/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:25:53 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 09:46:17 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

/* LES REFERENCES EN C++

Ressemblent aux pointeurs, permettent de creer des alias.

Caracteristiques :

- ne peuvent pas etre NULL;
- ne peuvent etre assignees qu'une seule fois.
- initialisation immediate obligatoirement, contrairement aux pointeurs.
- pas besoin d'utiliser l'operateur de dereferencement (*) pour acceder a la
valeur.

Ici on a donc :
&string : adresse memoire de la string,
&stringPTR : adresse memoire du pointeur stringPTR,
&stringREF : adresse memoire de la reference.
Ces trois adresses seront differentes, toutefois les 3 phrases affichees
seront bien "HI THIS IS BRAIN".

*/

int main(void) {

	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Adresse de la string en memoire : " << &string << std::endl;
	std::cout << "Adresse stockee dans stringPTR : " << stringPTR << std::endl;
	std::cout << "Adresse stockee dans stringREF : " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Valeur de la string : " << string << std::endl;
	std::cout << "Valeur pointee par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointee par stringREF : " << stringREF << std::endl;

	return 0;
}
