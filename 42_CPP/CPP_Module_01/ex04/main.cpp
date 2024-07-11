/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:36:42 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/14 11:06:57 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "ft_replace.hpp"

# define FAILURE 1
# define SUCCESS 0

/*
BUT DE L'EXERCICE :
Decouvrir les fonctions de travail sur les strings des biblis du C++; on veut
recoder la fonction replace en realite.

La std::ifstream va creer un fichier de lecture depuis son argument,
pareil avec ofstream, on cree cette fois un fichier qui sera un out d'ecriture.

Le principe est de lire le contenu du infile ligne a ligne avec getline() dans
une boucle while.
A chaque ligne lue, utiliser find de std::string pour trouver arg2. Si on
trouve notre arg2, on l'erase() et on concatener.
Une fois la ligne modifiee, on va l'ecrire dans le nouveau fichier. On repete.

En C++ il est plus simple de gerer les strings, pour obtenir le nouevau nom
du output par example : infile (par exemple "fichier.txt") est concatene au
suffixe pour creer le nouveau nom, ici "<fichier_infile>.replace".
*/

void ft_replace(const std::string &infile, const std::string &str1,
				const std::string &str2) {

	std::ifstream filename(infile.c_str());
	std::ofstream file_replace((infile + ".replace").c_str());

	if (filename.is_open() && file_replace.is_open()) {

		std::string line;
		while (std::getline(filename, line, '\0')) {

			size_t current = 0; // on cree un curseur pour run sur la line.
			size_t position = line.find(str1, current); // on cherche la première
			// occurrence de str1 dans la variable line à partir de l'index current.

			while (position != std::string::npos) { // tant que position existe
				file_replace << line.substr(current, position - current) << str2;
				current = position + str1.length();
				position = line.find(str1, current);
			}
			file_replace << line.substr(current) << std::endl;
		}
		filename.close(); // fermeture des fichiers ouverts precedemment.
		file_replace.close();}
	else {
		std::cerr << "File could not open" << std::endl;
		return ; }
}

int main(int ac, char **av) {

	if (micro_parsing(ac, av)) {
		std::string arg1(av[1]), arg2(av[2]), arg3(av[3]);
		ft_replace(arg1.c_str(), arg2.c_str(), arg3.c_str());
		return FAILURE; }
	else
		return FAILURE;
	return SUCCESS;
}
