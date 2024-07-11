/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:03:36 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 10:40:07 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {

    std::cout << "----- TEST 1 -----"<< std::endl;

    Array<char> arrayChar(8);
    char initChar[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++)
        arrayChar[i] = initChar[i];
    arrayChar.printArray();

    std::cout << std::endl;
    std::cout << "----- TEST 2 -----" << std::endl;

    Array<int> arrayInt(8);
    int initInt[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 8; i++)
        arrayInt[i] = initInt[i];
    arrayInt.printArray();

    std::cout << std::endl;
    std::cout << "----- TEST 3 -----" << std::endl;

    Array<double> arrayDouble(8);
    double initDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    for (int i = 0; i < 8; i++)
        arrayDouble[i] = initDouble[i];
    arrayDouble.printArray();

    std::cout << std::endl;
    std::cout << "----- TEST 4 -----" << std::endl;

    Array<int> A = arrayInt;
    A.printArray();

    return 0;
}



// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
