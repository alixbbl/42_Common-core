/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:59:17 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/10 14:55:29 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

public:
    Zombie();
    ~Zombie();

    bool        set_Name(std::string str);
    void        announce(void);

private:
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
