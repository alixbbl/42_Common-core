/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:41 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/13 14:47:22 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int>	tabDeInt;
	std::list<int>		listInt;

	try {
		for (int i = 0; i < 49; ++i)
			tabDeInt.push_back(i);
		std::vector<int>::iterator it1;
		it1 = easyfind(tabDeInt, 4);
		std::cout << "Value located = " << *it1 << std::endl;
		it1 = easyfind(tabDeInt, 48);
		std::cout << "Value located = " << *it1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }

	try {
		for (int i = 0; i < 100; ++i)
			listInt.push_back(i);
		std::list<int>::iterator it2;
		it2 = easyfind(listInt, 87);
		std::cout << "Value located = " << *it2 << std::endl;
		it2 = easyfind(listInt, -12);
		std::cout << "Value located = " << *it2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
	return 0;
}
