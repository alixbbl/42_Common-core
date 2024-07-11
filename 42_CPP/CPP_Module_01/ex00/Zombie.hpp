/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:04:26 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 14:28:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

    public:
        Zombie(); // constructeur par default
        ~Zombie(); // destructeur
        void        set_Name(std::string str);
        void        announce(void);

    private:
        std::string _name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif
