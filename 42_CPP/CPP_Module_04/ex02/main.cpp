/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:23:15 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 15:04:39 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdio>

int main()
{
	// AAnimal *test1 = new Dog;
	// AAnimal *test1 = new Cat;

	Animal *test1 = new Dog;
	Animal *test2 = new Cat;

	delete test1;
	delete test2;
	return 0;
}
