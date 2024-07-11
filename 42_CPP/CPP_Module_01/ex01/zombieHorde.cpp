/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:59:30 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/02 16:08:12 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

    Zombie* Horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        Horde[i].set_Name(name); }
    return Horde;
}
/*
On cree et on alloue un tableau d'objets de classe Zombie (Horde).
*/
