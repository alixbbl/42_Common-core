/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:28:00 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/19 09:26:47 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int ac, char **ag)
{
    try {
        if (ac != 2) {
            throw BitcoinExchange::inputRequired(); }

        try {
            BitcoinExchange btc;
            btc.exchangeBitcoin(ag[1]);
            return 0; }

        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1; } }

    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1; }

    return 0;
}

// si on trouve pas la date exacte, on doit aller chhercher celle en dessous de la premiere
// si c' est en dessous de la premiere, on renvoit la 1ere.
