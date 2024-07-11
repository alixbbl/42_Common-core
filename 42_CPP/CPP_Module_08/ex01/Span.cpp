/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:58:55 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 14:09:02 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Span::Span() { return ; }

Span::Span(int N) : _nbElements(N) { return ; }

Span::Span(const Span &src) {
	this->_content = src._content;
	this->_nbElements = src._nbElements;
}

Span &Span::operator=(const Span &src) {

	if (this != &src) {
		this->_content = src._content;
		this->_nbElements = src._nbElements; }
	return *this;
}

Span::~Span() { return ; }

/***************************** OTHER FUNCTIONS ********************************/

int	Span::isMax(std::vector<int> v) const {

	int max = 0;
	max = *std::max_element(v.begin(), v.end());
	return max;
}

int	Span::isMin(std::vector<int> v) const {

	int min = 0;
	min = *std::min_element(v.begin(), v.end());
	return min;
}

// ici on fait une copie du vector (const) que l'on pourra trier
// on cherche donc ensuite 2 a deux le plus petit ecart
int	Span::shortestSpan(void) const {

	if (_content.size() < 2)
		throw singleElement();

	std::vector<int>	sorted(_content);
	std::sort(sorted.begin(), sorted.end()); // simple appel de fonction
	unsigned int shortest = isMax(sorted) - isMin(sorted);

	for (size_t it = 0; it != _content.size(); it++) {
		unsigned int diff = abs(sorted[it] - sorted[it + 1]);
		if (diff < shortest)
			shortest = diff; }
	return shortest;
}

// Il suffit de chercher le min et le max et d'obtenir la difference entre les deux
int	Span::longestSpan(void) const {

	if (_content.size() < 2)
		throw singleElement();
	int longest = isMax(_content) - isMin(_content);
	return longest;
}

// on utilise push_back() qqui est une fonction membre de base pour ajouter un element
void	Span::addNumber(int nb) {

	if (_content.size() >= _nbElements)
		throw fullSpan();
	else
		_content.push_back(nb);
	return ;
}

// Le but est d'utiliser insert(), permet d'inserer un vctor dans un autre si la capacite est
// encore non atteinte : void insert (iterator position, size_type n, const value_type& val);
// Il faut creer un iterator pour inserer au bon endroit du vecteur.
void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {

	if (_content.size() > _nbElements or (std::distance(start, end) + _content.size()) > _nbElements)
		throw fullSpan();
	else
		_content.insert(_content.end(), start, end);
}

void	Span::printSpan(void) {

	if (_content.empty())
		std::cout << "Span is empty - No printing. "<< std::endl;
	else {
		std::cout << "Print span : "<< std::endl;
		for (std::vector<int>::iterator it = _content.begin(); it < _content.end(); it++) {
			std::cout << *it << std::endl; }
	}
}

/******************************** EXCEPTIONS **********************************/

const char* Span::fullSpan::what() const throw() {
		return ("Exception - Span is already full"); };

const char* Span::singleElement::what() const throw() {
		return ("Exception - Container has a single element..."); };
