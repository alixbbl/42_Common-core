/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:16:20 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/10 11:42:33 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
Copie profonde en C++:
La copie profonde consiste a creer en meme temps qu'une nouvelle instance, une copie
en memoire de chaque attribut. Ainsi, si on a une classe Personne avec une classe
Adresse contenue dedans, et que l' on souhaite creer une copie de Personne (une
nouvelle personne donc), il faut AUSSI creer une copie de Adress, afin que les
deux objets Personne ne partage pas la meme adresse via la ref/pointeur.
*/

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

Character::Character() : _name("unknown"), _nbItems(0) {

	for (int i = 0; i < MAX_MATERIA; i++) // on initialise l'inventory
		_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string const name) : _name(name), _nbItems(0) {

	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	std::cout << "Character -" << name << "- constructor called" << std::endl;
	return ;
}

Character::Character(const Character &src) {

	std::cout << "Character copy operator called" << std::endl;
	_nbItems = src._nbItems;
	_name = src._name;

	for (int i = 0; i < MAX_MATERIA; i++)
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	return ;
}

Character &Character::operator=(const Character &src) {

	std::cout << "Character assignation operator called" << std::endl;
	if (this != &src) {
		_nbItems = src._nbItems; // meme chose que recopie
		_name = src._name;
		for (int i = 0; i < MAX_MATERIA; i++) {
			delete _inventory[i];
			_inventory[i] = NULL; }
		// on nettoie l'inventory du character qui va recevoir la copie de src
		for (int i = 0; i < MAX_MATERIA; i++)
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character() {

	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++) {
		delete _inventory[i];
		_inventory[i] = NULL; } // gestion propre de memoire en c++.
	return ;
}
/*
Le fait de mettre à NULL après avoir appelé delete, est fait pour éviter les
problèmes potentiels d'accès à la mémoire après qu'elle a été libérée.
Une fois que delete est appelé, le pointeur ne pointe plus vers un objet valide
mais il peut toujours contenir l'adresse de mémoire précédemment allouée.
En affectant NULL après delete, on s'assure que le pointeur ne pointe vers rien
de potentiellement dangereux. Consideree comme une bonne pratique.
*/

/***************************** OTHER FUNCTIONS ******************************/

std::string const &Character::getName() const
{ return (this->_name); }


void Character::equip(AMateria* materia) {

	if (materia == NULL) {

		std::cout << "Materia is empty !" << std::endl;
		return ; }

	if (_nbItems < 4) {

		std::cout	<< "Materia " << materia->getType() << " added to inventory."
					<< std::endl;
		_inventory[_nbItems] = materia->clone();
		_nbItems++; }
	else
		std::cout << "Inventory is full !" << std::endl;
	return ;
}


void Character::unequip(int idx) {

	if (idx >= 0 && idx <= 3)
	{
		if (_inventory[idx] != NULL) {
			std::cout	<< "Materia " << _inventory[idx]->getType()
						<< " is suppressed from inventory."
						<< std::endl;
			delete _inventory[idx];
			_inventory[idx] = NULL;
			_nbItems--;
		}
		else
			std::cout << "Empty line." << std::endl;
	}
	else
		std::cout << "Unvalid index!" << std::endl;
}

void  Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx] == NULL)
			std::cout << "Nothing happens! (empty materia)" << std::endl;
		else {
			std::cout << std::endl;
			_inventory[idx]->use(target);
			std::cout << std::endl; }
		}
	else
		std::cout << "Unvalid index!" << std::endl;
}
