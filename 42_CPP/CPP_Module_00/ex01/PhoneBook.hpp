/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:51 by alibourb          #+#    #+#             */
/*   Updated: 2023/10/06 16:44:49 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SUCCESS 0

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook() : nbrContacts(0) {} // Constructeur (init a 0).
        void    _add(void);
        void    _search(void);
        void    _exit(void);
    private:
        int     nbrContacts;
        Contact _contacts[8];
        void    print_truncate(std::string str);
        void    display_allContacts(void);
};

#endif
