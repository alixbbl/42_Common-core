/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:32:39 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 12:02:42 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/************************* CONSTRUCTOR & DESTRUCTOR ***************************/

Harl::Harl(void) {

    return ; }

Harl::~Harl(void){

    return ; }

/***************************** PUBLIC FUNCTIONS *******************************/

/* On declare ici via le typedef un objet qui est un pointeur sur fonction membre
de la classe Harl. La declaration de fptr ET la creation de l'alias sont
concomittentes.
Si on va chercher l'adresse d'une fonction membre, on utilise la syntaxe
&NomDeLaClasse::NomDeLaFonction */

void    Harl::complain(std::string level) {

    typedef void ( Harl::*function_ptr )( void ); // pour abreger la ligne suiv.
    function_ptr    complaints[4] = { &Harl::debug, &Harl::info,
                                            &Harl::warning, &Harl::error };
    std::string	level_tab[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int it = 0; it < 4; it++) {
        if (level_tab[it] == level) {
            (this->*complaints[it])();
            return ; }
    }
    return ; }

/***************************** PRIVATE FUNCTIONS ******************************/

void    Harl::debug(void) {
    std::cout << "[ DEBUG ]"
            << "I love having extra bacon for my 7XL-double-cheese-triple-"
            << "pickle-specialketchup burger. I really do !" << std::endl; }

void    Harl::info(void) {
    std::cout << "[ INFO ]"
                << "I cannot believe adding extra bacon costs more money. You "
                << "didn’t put enough bacon in my burger ! If you did, "
                << "I wouldn’t be asking for more !" << std::endl; }

void    Harl::warning(void) {
    std::cout << "[ WARNING ]"
                << "I think I deserve to have some extra bacon for free. I’ve "
                << "been coming for years whereas you started working here "
                << "since last month." << std::endl; }

void    Harl::error(void) {
    std::cout << "[ ERROR ]"
                << "This is unacceptable ! I want to speak to the manager now."
                << std::endl; }
