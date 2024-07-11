/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:14:50 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 14:56:44 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/************************CONSTRUCTOR & DESTRUCTORS ****************************/

Zombie::Zombie() : _name("") {}

Zombie::~Zombie() {
        std::cout << "Destroying zombie: " << _name << std::endl; }

/********************************* SETTERS ************************************/

bool    Zombie::set_Name(std::string string) {
    this->_name = string;
    return true;
}

/***************************** OTHER FUNCTIONS *******************************/

Zombie *newZombie(std::string name) {

    Zombie *zombie = new Zombie();
    zombie->set_Name(name);
    return zombie; }

void    Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
