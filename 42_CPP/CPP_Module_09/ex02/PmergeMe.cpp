/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:08:35 by alibourb          #+#    #+#             */
/*   Updated: 2024/02/24 13:59:09 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	is_Digit(std::string str) {

	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

/************************ CONSTRUCTORS & DESTRUCTORS **************************/

PmergeMe::PmergeMe() { return; };

/*
Le constructeur avec parametre prend le tableau des params et traite en parsing
élément apres element, on construit ainsi la listeInit qui est affichee au debut.
*/
PmergeMe::PmergeMe(char **av) {

	int 			i = 1;
	long long int	nb;
	long long int	start;

	while (av[i])
	{
		if (is_Digit(av[i]))
			_listInit.push_back(av[i]);
		else
			throw PmergeMe::WrongParameterException();
		nb = atoll(av[i]);
		if (nb < 0)
			throw PmergeMe::NegatifIntegerException();
		else if (nb > INT_MAX)
			throw PmergeMe::WrongParameterException();
		else {
			_vectorInt.push_back(nb);
			_dequeInt.push_back(nb);
		}
		i++;
	}
	start = get_Time();
	sortContainer(_vectorInt);
	_timeVector = get_Time() - start;
	start = get_Time();
	sortContainer(_dequeInt);
	_timeDeque = get_Time() - start;
};

PmergeMe::PmergeMe(const PmergeMe &src){
	(void)src;
};

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs) {
	(void)rhs;
	return (*this);
};

PmergeMe::~PmergeMe() { return; };


/***************************** OTHER FUNCTIONS ********************************/

long long int	get_Time() // fonction idem philos
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

 // affichage de la liste des arguments tel que.
void	PmergeMe::before() const {
	std::string str = "Before:";

	for (size_t i = 0; i < _listInit.size(); i++)
		str+= (" " + _listInit[i]);
	std::cout << str << std::endl;
};

// affichage du vecteur de int apres le tri et le parsing.
void	PmergeMe::after() const {
	std::cout << "After: " ;
	for (size_t i = 0; i < _vectorInt.size(); i++)
		std::cout << " " << _vectorInt[i];
	std::cout << std::endl;
};

void	PmergeMe::timeVector() const {

	std::cout	<< "Time to process a range of " << _listInit.size()
				<< " elements with std::vector : " << _timeVector << " us"
				<< std::endl;
};

void	PmergeMe::timeDeque() const {
		std::cout	<< "Time to process a range of " << _listInit.size()
					<< " elements with std::deque   : " << _timeDeque << " us"
					<< std::endl;
};

void insertNOJ(std::vector<int> &Jacobsthal) {

	int value = 0;
	for (int i = 0; i < 32; ++i) {
		Jacobsthal.push_back(value);
		if (i % 2 == 0)
			value = value * 2 + 2;
		else
			value = value * 2 + 4;
	}
}

// Fonction de recherche binaire par insertion, on a une plage large de nombres de 0 a +++.
// on prend le milieu, si la valeur de l'element est en dessous ou au dessus du milieu,
// on coupe la moitie non concernee du spectre et on recommence jusqu'a trouver le bon emplacement
// du nombre.
template <typename T>
void	PmergeMe::binarySearchInsertion(T& main, int element) {

	int left = 0;
	int right = main.size() - 1;
	int middle;
	while (left <= right) {

		middle = left + (right - left) / 2;
		if (element < main[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
	main.insert(main.begin() + left, element); // on insere au bon endroit via insert()
};

/* Algorithme principal : */
template <typename T>
void PmergeMe::sortContainer(T &container) {

	std::vector<int> Jacobsthal; // creation et remplissage d'un container contenant la suite de Jacobsthal
	insertNOJ(Jacobsthal);
	// Tri en ordre croissant paire a paire
	for (size_t i = 0; i < container.size() - 1; i += 2)
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	// la condition d' arret est d'avoir un ensemble de containers contenant juste 2 elements tries.
	if (container.size() > 2) {
		T pair, impair; // Création des conteneurs pair et impair
		// Remplissage des conteneurs pair et impair
        for (size_t i = 0; i < container.size(); i += 2)
            pair.push_back(container[i]); // on y met les elements d'indice pair
        for (size_t i = 1; i < container.size(); i += 2)
            impair.push_back(container[i]); // on y met les elements d'indice impair
        // Tri récursif des paires dans le container pair
        sortContainer(pair); // on applique la division recursive au container "[pair]"

		//seconde partie de l'algo :
		int sizeMax = impair.size(); // on calcule la taille du container contenant les paires indice impair
		for (int index = 0; index < sizeMax; index++) {
			int j = 0;
			int finalIndex;
			while (index > Jacobsthal[j])
				j++;
			if (j != 0) {
				if (sizeMax - 1 <= Jacobsthal[j])
					finalIndex = sizeMax - (index - Jacobsthal[j - 1]);
				else
					finalIndex = Jacobsthal[j] + 1 - (index - Jacobsthal[j - 1]); }
			else
				finalIndex = 0;
			binarySearchInsertion(pair, impair[finalIndex]); // Insertion dans pair avec une recherche binaire
		}
		container = pair;
	}
}
/*
Dans la seconde partie de l'algo, la suite de Jacobsthal est utilisee pour fusionner les deux
containers pair et impair - pair ayant ete triee recursivement par ordre croissant auparavant -
on injecte chaque element de la sous-sequence "impair" via binarySearchInsertion(). Mais avant,
on itere sur tous les elemets de impair. Afin de savoir dans quelle endroit on insere notre
element de impair, on fait une sorte de recherche binaire sauf que ce sont les membres de la
suite de Jacobsthal qui remplacent "middle".
*/

/******************************** EXCEPTIONS **********************************/

const char *PmergeMe::WrongParameterException::what() const throw()
{ return ("Wrong parameter type. Only digits are allowed."); };

const char *PmergeMe::NegatifIntegerException::what() const throw()
{ return ("Wrong parameter type. Only positif integers are allowed."); };
