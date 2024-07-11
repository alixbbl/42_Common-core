/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:35:04 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/24 17:00:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "----- MUTANT STACK TEST -----" << std::endl;

	MutantStack<int> mutantstack;
	mutantstack.push(5);
	mutantstack.push(17);
	mutantstack.push(3);
	mutantstack.push(5);
	mutantstack.push(737);
	mutantstack.push(0);
	for (MutantStack<int>::iterator it = mutantstack.begin(); it != mutantstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "----- LIST TEST -----" << std::endl;

	std::list<int> mutantlist;
	mutantlist.push_back(5);
	mutantlist.push_back(17);
	mutantlist.push_back(3);
	mutantlist.push_back(5);
	mutantlist.push_back(737);
	mutantlist.push_back(0);
	for (std::list<int>::iterator it = mutantlist.begin(); it != mutantlist.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}
