/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:00:57 by alibourb          #+#    #+#             */
/*   Updated: 2023/05/09 12:28:19 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_lines(char *str, char c)
{
	unsigned int	nb_lines;

	nb_lines = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		while (*str)
		{
			if (*str != c)
			{
				nb_lines += 1;
				while (*str && *str != c)
					str++;
			}
			else
				str++;
		}
	}
	return (nb_lines);
}

char	*put_line(const char *str, char c)
{
	unsigned int	size_line;
	unsigned int	i;
	char			*line;

	if (!str)
		return (NULL);
	size_line = 0;
	while (str[size_line] && str[size_line] != c)
		size_line++;
	line = malloc(sizeof(*line) * (size_line + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < size_line)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	*free_split(char **tab)
{
	unsigned int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	nb_lines;

	nb_lines = count_lines((char *)str, c);
	tab = (char **)malloc(sizeof(*tab) * (nb_lines + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*str)
	{
		tab[i] = NULL;
		while (*str && *str == c)
			str++;
		if (!*str)
			break ;
		tab[i] = put_line(str, c);
		if (!tab[i])
			return (free_split(tab));
		while (*str && *str != c)
			str++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
