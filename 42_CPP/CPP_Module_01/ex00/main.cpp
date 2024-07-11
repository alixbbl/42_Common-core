/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:02:26 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 09:36:36 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name = "KIKI";
    Zombie *KikiZombie;

    std::cout << "-- Allocation on stack --" << std::endl;
    randomChump(name);

    std::cout << std::endl;

    std::cout << "-- Allocation on heap --" << std::endl;
    KikiZombie = newZombie(name);
    delete KikiZombie;
}
