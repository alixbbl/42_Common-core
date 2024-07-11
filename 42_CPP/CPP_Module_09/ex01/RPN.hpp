/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:59:13 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/24 12:34:52 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#pragma once

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <exception>

class RPN {

	public:
	RPN();
	~RPN();

	void	divisionByZeroDetection(std::string input);
	bool	isValidOperand(char c);
	void	execute(char *str);
	void	executeOperation(char c);

	class badInput : public std::exception {
		public :
			virtual const char* what() const throw();
	};
	class isNotADigitorValidOperand : public std::exception {
		public :
			virtual const char* what() const throw();
	};
		class divisionByZero : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	private:
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
		std::stack<int>		_stackRPN;
		int					_nb;
};

#endif
