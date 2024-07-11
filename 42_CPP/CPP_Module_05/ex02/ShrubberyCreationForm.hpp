/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:19:23 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 16:19:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#pragma once

class ShrubberyCreationForm : public AForm {

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm();

    // ajout d'une fonction execute derivee de la classe de base :
    void    execute(Bureaucrat const &executor) const ;

    private:
    std::string     _target;
};

#endif
