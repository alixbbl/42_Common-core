/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:18:05 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/11 11:10:57 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <cstdlib>
#include "AForm.hpp"

class AForm;

class Intern {

    public:
    Intern(void);
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();
        AForm* makeForm(std::string nameForm, std::string target);

    class FormNotFound: public std::exception {
        public:
            virtual const char* what() const throw(); };
};

#endif
