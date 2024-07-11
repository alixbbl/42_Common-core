/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:56:08 by alibourb          #+#    #+#             */
/*   Updated: 2023/12/16 14:41:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>

class Brain {

	public :
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	~Brain();

		int		getnbIdeas(void) const; // getter
		void	addIdeas(std::string new_idea); //setter
		void	printIdeas(void) const;

	private :
		std::string		_ideas[100];
		int				_nbIdeas;
};

#endif
