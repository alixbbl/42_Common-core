/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:38:47 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/13 12:08:53 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **ag) {

	if (ac != 2) {
		std::cout << "Wrong number of arguments !" << std::endl;
		return 1; }
	ScalarConverter::convert(ag[1]);
	return 0;
}
