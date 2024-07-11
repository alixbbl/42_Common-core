/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:59:13 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 14:05:40 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#pragma once

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>
#include <ctime>

class Span
{
    public:
    Span(int N);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

        void    addNumber(int n);
        void    addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        int     isMax(std::vector<int> v) const;
        int     isMin(std::vector<int> v) const;
        void	printSpan(void);

    private:
    Span();
        unsigned int                _nbElements;
        std::vector<int>            _content;

    class fullSpan: public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class singleElement: public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif

/*
La fonction membre addManyNumbers prend en parametre un vector de int,
et non un int simple.
*/
