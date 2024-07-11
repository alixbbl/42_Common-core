/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:18:54 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 17:18:56 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#pragma once

class PresidentialPardonForm : public AForm {

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
    ~PresidentialPardonForm();

    // ajout d'une fonction execute derivee de la classe de base
    void    execute(Bureaucrat const &executor) const ;

    private:
    std::string     _target;
};

#endif
