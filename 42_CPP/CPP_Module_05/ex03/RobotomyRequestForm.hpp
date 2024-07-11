/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:18:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/08 17:18:44 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#pragma once

class RobotomyRequestForm : public AForm {

    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
    ~RobotomyRequestForm();

    // ajout d'une fonction execute derivee de la classe de base :
    void    execute(Bureaucrat const &executor) const ;

    private:
    std::string     _target;
};

#endif
