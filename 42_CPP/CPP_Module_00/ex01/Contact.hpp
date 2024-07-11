/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:44:44 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/08 18:19:00 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

/*

Dans la classe Public sont stockees les donnees et methodes (fonctions), qui
peuvent etre utilisees et modifiees partout dans le programme, on y place donc
nos constructeurs, nos setters et nos getters. Ils permettent d'aller recuperer
les data mises en Private, qui elles ne doivent pas etre modifiables. En l'occu-
rence, on souhaite garder privees les donnees des users, ainsi que les fonc-
tions qui permettent de verifier les formats de ces infos.

*/

class Contact {

    public:
    Contact() : _firstName(""), _lastName(""), _nickName(""),
    _phoneNumber(""), _darkestSecret("") {}
    int         ID;
    void        set_firstName();
    void        set_lastName();
    void        set_nickName();
    void        set_phoneNumber();
    void        set_darkestSecret();
    void        display_Contact(int _contactId);
    std::string get_firstName();
    std::string get_lastName();
    std::string get_nickName();
    std::string get_phoneNumber();
    std::string get_darkestSecret();

    void        exit_contact();

    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;
    bool        only_digits(std::string str);
    bool        only_alpha(std::string str); };

#endif
