/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:43:59 by alibourb          #+#    #+#             */
/*   Updated: 2023/10/15 17:33:00 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REPLACE_HPP
# define FT_REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

bool	micro_parsing(int ac, char **av);
bool	isValidFile(const std::string &filename);
bool	only_alpha(std::string str);
void	ft_replace(const std::string &filename, const std::string &str1,
					const std::string &str2);

#endif
