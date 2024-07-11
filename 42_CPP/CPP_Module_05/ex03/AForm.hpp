/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:49 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 17:19:27 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

/*
Cette classe de base est non-instanciable.

Comment determiner quelles methodes de AForm (classe de base), doivent etre
des virtuelles simples, ou alors des virtuelles pures ?
Une methode virtuelle pure ne sera PAS implementee dans la classe de base et donc
OBLIGATOIREMENT dans les classes filles. On choisit donc de garder en virtuel les
methodes communes a toutes, et pures, les methodes qu'il faut implementer differem-
ment pour chaque classe fille.
*/

class Bureaucrat;

class AForm
{
    public:
    AForm(void);
    AForm(std::string const formName, bool status, const unsigned int gradeToSign,
			const unsigned int gradeToExec);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    virtual ~AForm();

        virtual std::string const       getFormName(void) const;
        virtual bool                    getSignedStatus(void) const ;
        virtual unsigned int            getGradeToSign(void) const ;
        virtual unsigned int            getGradeToExecute(void) const ;

        class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw(); };

        class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw(); };

        virtual void    beSigned(Bureaucrat &bureaucratos);
        /* New function for Form class */
        virtual void    execute(Bureaucrat const &executor) const = 0; // seule virtuelle pure

    private: // demande de la consigne, on utilisera les getters dans les autres class filles.
        std::string const       _formName;
        bool                    _signed;
        const unsigned int      _gradeToSign;
        const unsigned int      _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
