/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:28:09 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/24 17:31:26 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

void printMap(const std::map<std::string, float>& myMap) {

    std::map<std::string, float>::const_iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

BitcoinExchange::BitcoinExchange() {

    fillMapFromCSV();
    return ; }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{ *this = src; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {

    if (this != &src) {
        this->_bitcoinRates = src._bitcoinRates; }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{ return ; }

// std::istream &operator>>(std::istream &is, std::pair<std::string, float> &p) {
//     return is >> p.first >> p.second; }

/******************************** EXCEPTIONS ********************************/

const char* BitcoinExchange::inputRequired::what() const throw() {
    return "Error : input is required.";
}

const char* BitcoinExchange::couldNotOpenFile::what() const throw() {
    return "Error : could not open file.";
}

const char* BitcoinExchange::notAPositiveNumber::what() const throw() {
    return "Error : not a positive number.";
}

const char* BitcoinExchange::tooLargeANumber::what() const throw() {
    return "Error : too large a number.";
}

const char* BitcoinExchange::notANumber::what() const throw() {
    return NULL;
}

/***************************** OTHER FUNCTIONS ******************************/

bool	BitcoinExchange::isDouble(const std::string &literal) {

	unsigned long	i = 0;

	if (literal[0] == '-' || literal[0] == '-')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == '.' && std::isdigit(literal[i + 1]))
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal.size() == i)
		return (true);
	return (false);
}

bool	BitcoinExchange::isFloat(const std::string &literal) {

	unsigned long	i = 0;

	if (literal == "-inff" or literal == "+inff" or literal == "nanf")
		return (true);
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == '.' && std::isdigit(literal[i + 1]))
		i++;
	else
		return (false);
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == 'f')
		i++;
	else
		return (false);
	if (literal.size() == i)
		return (true);
	return (false);
}

void BitcoinExchange::displayResult(std::string date, std::string valueStr) {

    float value = std::atof(valueStr.c_str());
    std::map<std::string, float>::iterator closestDate = _findDate(date);
    std::cout << closestDate->first << " => " << value << " = "
              << (closestDate->second * value) << std::endl;
}

std::map<std::string, float>::iterator BitcoinExchange::_findDate(const std::string& date) {

    std::map<std::string, float>::iterator it = _bitcoinRates.find(date);
    if (it != _bitcoinRates.end())
        return it;
    else {
        std::map<std::string, float>::iterator next = _bitcoinRates.lower_bound(date);
        // Si la date est inférieure à toutes les dates dans la map
        if (next == _bitcoinRates.begin())
            return next;
        // Si la date est supérieure à toutes les dates dans la map
        else if (next == _bitcoinRates.end()) {
            std::map<std::string, float>::iterator prev = next;
            return --prev; }
        // Si on est entre deux dates, retourner la date inférieure
        else  {
            std::map<std::string, float>::iterator prev = next;
            --prev;
            return prev; }
    }
}

bool    BitcoinExchange::isValidValue(std::string valueStr) {

    try {
        if (!isDouble(valueStr) && !isFloat(valueStr) && valueStr != ""
            && valueStr != "date | value") {
            // std::cout << "Le programme ne reconnait pas : " << valueStr << std::endl;
            throw BitcoinExchange::notANumber(); }
        long value = std::atoll(valueStr.c_str());
        if (value < 0)
            throw BitcoinExchange::notAPositiveNumber();
        else if (value > 1000)
            throw BitcoinExchange::tooLargeANumber();
        return true; }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false; }
}

// utilisation de la methode getline pour remplir les paires de la map.
void    BitcoinExchange::fillMapFromCSV(void) {

    std::ifstream filemap("data.csv");
    if (!filemap.is_open()) {
        throw BitcoinExchange::couldNotOpenFile();
        exit(1); }

    bool firstLine = true;
    std::string line;

    while (std::getline(filemap, line))
    {
        if (firstLine == true) {
            if (line != "date,exchange_rate") {
                return ; }
            firstLine = false; }

        std::istringstream iss(line); // on fait de la ligne un flux d'entree line vers iss.
        std::string date, valueStr;
        std::getline(iss, date, ','); // getline vient remplir date avec la data du flux iss avant la ",".
        std::getline(iss, valueStr, '\n');
        this->_bitcoinRates[date] = std::strtof(valueStr.c_str(), NULL);
    }
    filemap.close();
}

bool    BitcoinExchange::isValidDate(std::string dateString) {

    struct tm timeStruct;
    char date_str[11];

    std::memset(&timeStruct, 0, sizeof(struct tm));

    strptime(dateString.c_str(), "%Y-%0m-%0d", &timeStruct);
    strftime(date_str, sizeof(date_str), "%Y-%0m-%0d", &timeStruct);
    if (strcmp(dateString.c_str(), date_str) != 0)
        return false;
    return true;
}

void    BitcoinExchange::exchangeBitcoin(char *ag1) {

    std::string     line;
    bool            isFirstLine = true;
    std::ifstream   inputFile(ag1); // creation du infile.

    try {
        if (inputFile.is_open()) {

            while (std::getline(inputFile, line)) {
                if (!line.empty()) {
                    if (isFirstLine == true) {
                        if (line != "date | value") {
                            std::cerr << "Error : Input file is not correct. Missing date | value." << std::endl;
                            return ; }
                        isFirstLine = false;
                    }
                    else if ( isFirstLine == false) {
                        if (line.size() > 13 && line.size() < 23) {
                            std::string date = line.substr(0, 10);
                            std::string valueStr = line.substr(13);
                            if (isValidDate(date) and (isValidValue(valueStr)))
                                displayResult(date, valueStr);
                            else
                                std::cout << "Error: bad input => " << line << std::endl;
                        }
                        else {
                            if (line != "date | value")
                                std::cout << "Error: bad input => " << line << std::endl; }
                    }
                }
            }
            inputFile.close(); }
        else
            throw BitcoinExchange::couldNotOpenFile(); }
    catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
}

