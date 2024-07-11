/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:35:04 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/21 09:27:58 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "Error: Wrong amount of arguments" << std::endl;
		return (1);
	}
	try {
		PmergeMe	pgm(av);

		pgm.before();
		pgm.after();
		pgm.timeVector();
		pgm.timeDeque();
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	return (0);
}

/* TEST a 3000 :

Entrez la commande :
./PmergeMe $(seq 1 100000 | shuf -n 3000 | tr '\n' ' ')
Possible de mettre directement dans un fichier (>.txt)
*/
