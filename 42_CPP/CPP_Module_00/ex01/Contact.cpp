/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:15 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/08 18:23:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

/******************************************************************************/
/*                                  SETTERS                                   */
/******************************************************************************/

void    Contact::set_firstName() {

    std::string data;
    while (1) {

        std::cout << "First Name : ";
        std::getline(std::cin, data);
        if (std::cin.eof()) // test fonction inside contact
            exit_contact();
        if (data.empty()) {
            std::cout << "A firstname is mandatory." << std::endl;
            continue ; }
        if (!only_alpha(data)) {
            std::cout << "Error : You can only use letters and hyphens."
                << std::endl;
                continue ;}
        data[0] = std::toupper(data[0]);
        this->_firstName = data;
        break ; }
    return ; }

void    Contact::set_lastName() {

    std::string data;
    while (1) {

        std::cout << "Last Name : ";
        std::getline(std::cin, data);
        if (std::cin.eof())
            exit_contact();
        if (data.empty()) {
            std::cout << "A lastname is mandatory." << std::endl;
            continue ; }
        if (!only_alpha(data)) {
            std::cout << "Error : You can only use letters and hyphens."
                << std::endl;
                continue ; }
        for (std::string::iterator it = data.begin(); it < data.end() ; it++)
            *it = std::toupper(*it);
        this->_lastName = data;
        break ; }
    return ; }

void    Contact::set_nickName() {

    std::string data;
    while (1) {

        std::cout << "Nickname : ";
        std::getline(std::cin, data);
        if (std::cin.eof())
            exit_contact();
        if (data.empty()) {
            std::cout << "A nickname is mandatory." << std::endl;
            continue ; }
        if (!only_alpha(data)) {
            std::cout << "Error : You can only use letters and hyphens."
                << std::endl;
                continue ; }
        data[0] = std::toupper(data[0]);
        this->_nickName = data;
        break ; }
    return ; }

void    Contact::set_phoneNumber() {

    std::string data;
    while (1) {

        std::cout << "Phone Number : ";
        std::getline(std::cin, data);
        if (std::cin.eof())
            exit_contact();
        if (data.empty()) {
            std::cout << "A phone number is mandatory." << std::endl;
            continue ; }
        if (!only_digits(data)) {
            std::cout << "Error : You can only use plus sign and digits."
                << std::endl;
                continue ; }
        this->_phoneNumber = data;
        break ; }
    return ; }

void    Contact::set_darkestSecret() {

    std::string data;
    while (1) {

        std::cout << "Darkest Secret : ";
        std::getline(std::cin, data);
        if (std::cin.eof())
            exit_contact();
        if (data.empty()) {
            std::cout << "A secret is mandatory." << std::endl;
            continue ; }
        this->_darkestSecret = data; // ne prend pas les \n avec le GNL.
        break ; }
    return ; }

/******************************************************************************/
/*                                   GETTERS                                  */
/******************************************************************************/

std::string Contact::get_firstName(){
    return (this->_firstName);
}

std::string Contact::get_lastName() {
    return (this->_lastName);
}

std::string Contact::get_nickName() {
    return (this->_nickName);
}

std::string Contact::get_phoneNumber() {
    return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret() {
    return (this->_darkestSecret);
}

/******************************************************************************/
/*                                CONTACT UTILS                               */
/******************************************************************************/

bool    Contact::only_digits(std::string str) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isdigit(*it) && *it != ' ' && *it != '+')
            return false;
    }
    return true;
}

bool    Contact::only_alpha(std::string str) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isalpha(*it) && *it != ' ' && *it != '+')
            return false;
    }
    return true;
}

/******************************************************************************/
/*                                DISPLAY UTILS                               */
/******************************************************************************/

void Contact::display_Contact(int _contactId) {

    std::cout << "Contact ID: " << _contactId << std::endl;
    std::cout << "First Name: " << this->_firstName << std::endl;
    std::cout << "Last Name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickName << std::endl;
    std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

/******************************************************************************/
/*                                    UTILS                                   */
/******************************************************************************/

void    Contact::exit_contact(void) {
    std::cout << "Bye bye !" << std::endl;
    exit (SUCCESS); }
