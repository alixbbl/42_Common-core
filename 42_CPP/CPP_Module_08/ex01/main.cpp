/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:44:03 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/13 14:57:28 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "--------------- MAIN CONSIGNE -----------------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----------------- MAIN PERSO ------------------" << std::endl;
	try {
		Span bis(sp);
		sp.printSpan();
		bis.printSpan();
		std::cout << bis.shortestSpan() << std::endl;
		std::cout << bis.longestSpan() << std::endl;
		bis.addNumber(52);
	}
	catch (std::exception &exception)
		{ std::cout << exception.what() << std::endl; }

	try {
		Span newSpan = Span(10);
		newSpan.printSpan();
		newSpan.addNumber(52);
		newSpan.addNumber(-73);
		newSpan.addNumber(6);
		newSpan.addNumber(-2);
		newSpan.addNumber(16);
		newSpan.addNumber(3);
		newSpan.printSpan();
		std::cout << "Ranges for newSpan : " << std::endl;
		std::cout << newSpan.shortestSpan() << std::endl;
		std::cout << newSpan.longestSpan() << std::endl;
	}
	catch (std::exception &exception)
		{ std::cout << exception.what() << std::endl; }

	std::cout << "----- TEST WITH 10 000 INTEGERS ----- "<< std::endl;
	try {
		srand(time(NULL));
		Span bigSpan = Span(10000);
		std::vector<int> toAdd;
		for (int i = 0; i != 10000; i++) {
			int newInt = rand();
			toAdd.push_back(newInt);
		}
		bigSpan.addNumber(toAdd.begin(), toAdd.end());
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception &exception)
		{ std::cout << exception.what() << std::endl; }
	return 0;
}
