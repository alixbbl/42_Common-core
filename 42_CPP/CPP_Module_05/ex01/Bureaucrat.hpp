/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:49 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:04:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdlib>
#include <iostream>
#include <cstdio>

#include "Form.hpp"

#pragma once

class Form;

class Bureaucrat
{
    public:
    Bureaucrat();
    Bureaucrat(std::string const name, unsigned int grade);
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &src);
    ~Bureaucrat();

        std::string const   getName(void) const;
        unsigned int        getGrade(void) const;
        void                downGrade(void);
        void                upGrade(void);

        class GradeTooHighException: public std::exception { // IMPORTANT
			public:
				virtual const char* what() const throw(); };

        class GradeTooLowException: public std::exception { // IMPORTANT
			public:
				virtual const char* what() const throw(); };

        /* New function for Bureaucrat class */
        void    signForm(Form &someForm);

    private:
        std::string const    _name;
        unsigned int         _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

/* travail dans la classe donc inutile que les fonctions retournent des int
ou prennent des parametres comme les refs.
Il existe une classe execption dans la bibliotheque standard qui contient
plusieurs exceptions deja prevues. Si on veut a son tour personnaliser
une classe pour les erreurs, on cree une classe heritant de exception donc
avec public std::exception.

virtual const char* what() const throw(); :

La fonction what() est une fonction virtuelle pure déclarée dans la classe
de base std::exception. En la déclarant dans ta classe dérivée
GradeTooHighException, tu la redéfinis pour fournir un message d'erreur
spécifique à cette exception.

virtual : Indique que la fonction est virtuelle et peut être redéfinie par
            des classes dérivées.

const char* : Indique que la fonction renvoie un pointeur constant vers
                un tableau de caractères, c'est-à-dire une chaîne de caractères en C.

const après la fonction : Indique que la fonction ne modifie pas l'état de l'objet.

throw() : Indique que la fonction ne lance pas d'exceptions
            (équivalent de throw() en C++ avant C++11). Convention de c++.
*/
