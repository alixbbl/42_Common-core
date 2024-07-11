/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:21:10 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 10:47:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

MateriaSource::MateriaSource() : _nb(0) {

	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_materias[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src) {

	*this = src; // recopie complete grace a la surcharge =.
	std::cout << "MateriaSource copy operator called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {

	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &src) {
		_nb = src._nb;
		for (int i = 0; i < MAX_MATERIA; i++)
			_materias[i] = src._materias[i];
	}
	return *this;
}

MateriaSource::~MateriaSource() {

	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < _nb; i++) {
		delete _materias[i];
		_materias[i] = NULL; }
	return ;
}
/* on ne peut pas utiliser delete[] car cela n' est possible que si le tableau
a ete cree avec new, ce qui n' est pas le cas car clone() a ete utilise */


/***************************** OTHER FUNCTIONS ******************************/

/*
Il s'agit d'ajouter une Materia au tableau de 4 maximum.
*/
void	MateriaSource::learnMateria(AMateria *materia) {

	if (_nb >= MAX_MATERIA) {
		std::cout << "MateriaSource is already full!" << std::endl;
		return ; }
	else if (materia == NULL) {
		std::cout << "Empty name of Materia !" << std::endl;
		return ; }
	else {
		_materias[_nb] = materia;
		_nb++; }
}

/* Cette fonction prend un type de materia en argument et fait appel a clone()
qui appartient a la classe de base. Si aucun type n' est trouve, on renvoie NULL*/
AMateria	*MateriaSource::createMateria(std::string const &type) {

	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_materias[i] && _materias[i]->getType() == type) { // correction du segfault
			return _materias[i]->clone(); }
	}
	std::cout	<< "Can't create a AMateria, it's an abstract class."
				<< std::endl;
	return NULL;
}
