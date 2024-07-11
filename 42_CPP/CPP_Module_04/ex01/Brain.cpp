/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:56:05 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/09 14:00:30 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Brain::Brain() : _ideas() {

	_nbIdeas = 0;
	std::cout << " I have a brain!! " << std::endl;
}

Brain::Brain (const Brain &src)
{
	*this = src; // on fait appel ici a la surcharge de l'operateur d'affectation
	// this->operator=(src); est une autre facon de l'ecrire
	std::cout << "Just copied a new brain by copy!" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	}
	std::cout << "Just copied a new brain with assignation operator!" << std::endl;
	return *this;
}

Brain::~Brain() {

	std::cout << " I... I have no more brain!! " << std::endl; }

/****************************** OTHER FUNCTIONS ******************************/

void Brain::addIdeas(std::string new_idea) {

	if (_nbIdeas == 0) {

		for (int i = 0; i < 10; i++) {
			if (i == 0)
				_ideas[0] = "First idea is always to EAT";
			else if (i == 99)
				_ideas[99] = "Last idea is always to SLEEP";
			else
				_ideas[i] = "Choose your path baby";
		}
	}

	_ideas[_nbIdeas % 100] = new_idea;
	_nbIdeas++;
}


void Brain::printIdeas(void) const {

	for (int i = 0; i < _nbIdeas; i++)
		puts(_ideas[i].c_str()); // fonction de print
}

int		Brain::getnbIdeas(void) const {

	return (this->_nbIdeas);
}
