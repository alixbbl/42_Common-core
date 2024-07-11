/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:01:56 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/03 11:56:46 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
Toujours preciser avant d'utiliser une fonction (getter ou setter), ou une
instance, a quelle classe elles appartiennent.
Utilisation du mot-clef "this->", de type pointeur, et qui permet d'acceder
a l'objet actuel.

Fonction get() : lit un seul char a partir de stdin.

Fonction getline() : lit et stocke la string passee en stdin, \n inclut, lu
mais pas stocke. Elle prend la ligne jusqu'au \n, et le remplace par \0.
*/

/******************************************************************************/
/*                                   ADD                                      */
/******************************************************************************/

void    PhoneBook::_add(void) {

    Contact newContact;

    newContact.set_firstName();
    newContact.set_lastName();
    newContact.set_nickName();
    newContact.set_phoneNumber();
    newContact.set_darkestSecret();
    if (this->nbrContacts < 8) {
        this->_contacts[this->nbrContacts] = newContact;
        this->nbrContacts++;}
    else {
        for (int i = 1; i < 8; i++)
            this->_contacts[i - 1] = this->_contacts[i];
        this->_contacts[7] = newContact; }
}

/******************************************************************************/
/*                                  SEARCH                                    */
/******************************************************************************/

void    PhoneBook::_search(void) {

    std::string research_input;
    int         ID_research;

    if (!PhoneBook::nbrContacts) {
        std::cout << "You have no contact yet !" << std::endl;
        return ; }
    this->display_allContacts();
    std::cerr << "Please enter an ID to find a contact :" << std::endl;

    while(true) {
        std::getline(std::cin, research_input);
        if (research_input == "exit" || std::cin.eof())
            this->_exit();
        std::cout << "You asked for : " << research_input << "!" << std::endl;
        ID_research = std::atoi(research_input.c_str());
        if (ID_research < 1 || ID_research > 8
            || ID_research > this->nbrContacts)
            std::cerr << "Please enter valid ID (1 to "
                << PhoneBook::nbrContacts << ")." << std::endl;
        else
            break ; }

    _contacts[ID_research - 1].display_Contact(ID_research); }

/******************************************************************************/
/*                                  EXIT                                      */
/******************************************************************************/

void    PhoneBook::_exit(void) {
    std::cout << "Bye bye !" << std::endl;
    exit (SUCCESS); }

/******************************************************************************/
/*                             DISPLAY UTILS                                  */
/******************************************************************************/

void	PhoneBook::print_truncate(std::string str) {
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void    PhoneBook::display_allContacts(void) {

	std::cout << "\033[0m╔════════════╦════════════╦════════════╦════════════╗"
        << std::endl << "║ ";
	std::cout << std::setw(10) << "Id    " << " ║ ";
	std::cout << std::setw(10) << "First Name" << " ║ ";
	std::cout << std::setw(10) << "Last Name " << " ║ ";
	std::cout << std::setw(10) << "Nickname " << " ║ " << std::endl;

	for (int i = 0; i < PhoneBook::nbrContacts ; i++)
	{
		std::cout << "╠════════════╬════════════╬════════════╬════════════╣"
            << std::endl;
		std::cout << "║ " << std::setw(10) << i + 1 << " ║ ";
		PhoneBook::print_truncate(this->_contacts[i].get_firstName());
		std::cout << " ║ ";
		PhoneBook::print_truncate(this->_contacts[i].get_lastName());
		std::cout << " ║ ";
		PhoneBook::print_truncate(this->_contacts[i].get_nickName());
		std::cout << " ║" << std::endl;
	}
	std::cout << "╚════════════╩════════════╩════════════╩════════════╝\033[m"
        << std::endl;
}
