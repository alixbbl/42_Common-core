/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:16:47 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/24 13:58:27 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <sys/time.h>
# include <iomanip>
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# define INT_MAX 2147483647

class PmergeMe {

	public:
		PmergeMe(char **av);
		~PmergeMe();

		void	before() const;
		void	after() const;
		void	timeVector() const;
		void	timeDeque() const;

		class WrongParameterException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NegatifIntegerException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &rhs);

		template <typename T>
		void	sortContainer(T &container);
		template <typename T>
		void	binarySearchInsertion(T& container, int element);

		std::vector<std::string>		_listInit;
		std::vector<int>				_vectorInt;
		std::deque<int>					_dequeInt;
		long long int					_timeVector;
		long long int					_timeDeque;
};

long long int	get_Time();
