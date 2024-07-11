/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:59:04 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 15:08:33 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

#define NBR_MIN 0
#define NBR_MAX 500

// Le premier argument est le nbre, le second est le nom.
int main(int ac, char **av) {

    (void)ac;
    std::string name;

    if (!av[1]) {
        std::cout << "Two valid arguments are required." << std::endl;
        return 0; }
    if (!av[2])
        name = "ZOMBIE";
    else
        name = av[2];
    int N = atoi(av[1]);

    if (N > NBR_MIN && N < NBR_MAX) {

       Zombie* Horde = zombieHorde(N, name);
        for (int i = 0; i < N; i++) {
            Horde[i].announce(); }
        delete[] Horde;
    }
    else
        std::cout   << "Calm down, please enter some "
                    << "realistic numbers (0 to 500)." << std::endl;
    return 0;}
