/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:33:49 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/22 18:47:29 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#pragma once

class Bureaucrat;

class Form
{
    public:
    Form(void);
    Form(std::string const formName, bool status, const unsigned int gradeToSign,
			const unsigned int gradeToExec);
    Form(Form const &src);
    Form &operator=(Form const &src);
    ~Form();

        std::string const       getFormName(void) const;
        bool                    getSignedStatus(void) const;
        unsigned int            getGradeToSign(void) const;
        unsigned int            getGradeToExecute(void) const;

        class GradeTooHighException: public std::exception { // IMPORTANT
			public:
				virtual const char* what() const throw(); };

        class GradeTooLowException: public std::exception { // IMPORTANT
			public:
				virtual const char* what() const throw(); };
        
        /* New function for Form class */
        void    beSigned(Bureaucrat &bureaucratos);

    private:
        std::string const       _formName;
        bool                    _signed;
        const unsigned int      _gradeToSign;
        const unsigned int      _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif
