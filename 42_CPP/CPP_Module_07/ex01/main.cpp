/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:03:16 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 11:12:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {

    int intArray[5] = {9, 56, 3, 1, 908};
    double doubleArray[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    std::string stringArray[4] = {"hello", "hi_babe", "mygod", "ciao"};

    std::cout << "******* PRINT ARRAY *******" << std::endl;
    printArray(intArray, 5);
    printArray(doubleArray, 7);
    printArray(stringArray, 4);
    std::cout << std::endl;

    std::cout << "******* TEST WITH ITER *******" << std::endl;
    iter(intArray, 5, &printElement);
    iter(doubleArray, 7, &printElement);
    iter(stringArray, 4, &printElement);

    return 0;
}


// // main correction
// int main() {
//     int tab[] = {0, 1, 2, 3, 4};
//     Awesome tab2[5];
//     iter(tab, 5, print);
//     iter(tab2, 5, print);
//     return 0;
// }
