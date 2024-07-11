/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:27:42 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 12:24:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

class ElementNotFound: public std::exception {
	public:
		virtual const char* what() const throw() { return "Exception : Element not found"; };
};

// // Cette fonction est interdite par la correction (pas par le sujet)
// template<typename T>
// typename T::iterator	easyfind(T& container, int a) {

// 	typename T::iterator it;
// 	for (it = container.begin(); it != container.end(); it++) {
// 		if (*it == a) {
// 			std::cout << a << " was found !" << std::endl;
// 			return it; }
// 	}
// 	throw ElementNotFound();

// la correction force a utiliser les fonctions de <algorithm>
template<typename T>
typename T::iterator	easyfind(T& container, const int a) {

	typename T::iterator ret; // on cree a nouveau un iterator car c'est le type de retour
	ret = find(container.begin(), container.end(), a);
	if (ret == container.end())
		throw ElementNotFound();
	return ret;
}

#endif

/*
La syntaxe typename T::iterator est utilisée parce que iterator est une
dépendance de type dans le contexte de templates. Lorsque vous travaillez avec
des templates, le compilateur ne sait pas nécessairement que iterator est un
type, car cela dépend du type concret fourni au template.

La syntaxe typename T::iterator informe le compilateur que iterator est un type
membre de la classe ou de la structure T. Cela aide le compilateur à comprendre
que iterator est bien un type et pas une variable ou une fonction.

En résumé, l'utilisation de typename est nécessaire lorsque vous référencez
un type qui dépend du template pour être défini. Cela aide le compilateur à
résoudre ces dépendances de type de manière correcte.
*/
