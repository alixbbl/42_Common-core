/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:40:10 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/19 14:14:19 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define TRASH 0

class ScalarConverter
{
    public:
    ~ScalarConverter();
        static void convert(const std::string &str);

        static bool	isChar(const std::string &literal);
        static bool	isInt(const std::string &literal);
        static bool	isFloat(const std::string &literal);
        static bool	isDouble(const std::string &literal);
        static int	determineType(const std::string &literal);

        static void	convertChar(char c);
        static void	convertInt(int a);
        static void	convertFloat(float f, std::string str);
        static void	convertDouble(double d, std::string str);

        static void printChar(char c);
        static void printInt(int a);
        static void printFloat(float f);
        static void printDouble(double d);

    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
};

#endif

/*
Comme on ne doit pas pouvoir instancier, on passe les constructeurs en private.
Les fonctions convert() et les fonctions auxilliaires sont mises en static pour
etre utilisables partout (la classe est non instanciable).
*/
