/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:44:03 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/19 17:55:03 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

/*
- On utilise ici la stack.
- Le RPN est une ecriture selon laquelle les chiffres sont mis en 1er, suivis des
operandes par exemple : "3 4 +" est en realite "3 + 4".
- Les operandes suivantes sont a prendre en charge : + - / *
*/


int main(int ac, char **ag)
{
	try {
		if (ac != 2)
			throw RPN::badInput();
		try {
			RPN rpn;
			rpn.execute(ag[1]);
		}
		catch (const std::exception &e)
			{ std::cerr << e.what() << std::endl; }
		return 0;
	}
	catch (const std::exception &e)
		{ std::cerr << e.what() << std::endl; }
}
