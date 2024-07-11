/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:02:53 by alibourb          #+#    #+#             */
/*   Updated: 2023/10/13 12:02:54 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name) {

    Zombie chumpchump;

    if (!name.empty()) {
        chumpchump.set_Name(name);
        chumpchump.announce(); }
    else
        std::cout << "Please enter a valid name." << std::endl;
}
