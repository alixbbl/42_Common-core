/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:29:28 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/24 12:15:22 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <exception>

#define INT_MAX 2147483647

class BitcoinExchange {

    public:
    BitcoinExchange();
    ~BitcoinExchange();

        void    fillMapFromCSV(void);
        void    exchangeBitcoin(char *ag1);
        void    displayResult(std::string date, std::string valueStr);
        bool    isValidDate(std::string dateString);
        bool    isValidValue(std::string valueStr);
        bool	isDouble(const std::string &literal);
        bool	isFloat(const std::string &literal);
        std::map<std::string, float>::iterator _findDate(const std::string& date);

        class inputRequired : public std::exception {
            public :
                virtual const char* what() const throw();
        };
        class couldNotOpenFile : public std::exception {
            public :
                virtual const char* what() const throw();
        };
        class notAPositiveNumber : public std::exception {
            public :
                virtual const char* what() const throw();
        };
        class tooLargeANumber : public std::exception {
            public :
                virtual const char* what() const throw();
        };
        class notANumber : public std::exception {
            public :
                virtual const char* what() const throw();
        };

    private :
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);

    std::map<std::string, float>    _bitcoinRates;
};

#endif
