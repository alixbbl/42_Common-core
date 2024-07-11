/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:00:57 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/02 11:10:33 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_lines(char *str, char c)
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
// count_lines compte le nombre de mots de la str source, donc du nbre futur
// de lignes du tableau. Tant que la valeur pointee est == c, on avance.

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

static void	*free_split(char **tab)
{
	unsigned int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}
// free du split en cascade.*/

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

// int main(void)
// {
// 	char    **res;
// 	char	test[] = "lorem liguper congue, euismod non, mi.";
//         int i;
//         i = 0;
//         res = ft_split(test, 'i');
//         while (i < count_lines(test, 'i'))
//         {
//             printf("%s\n", res[i]);
//             i++;
//        	}
// 		printf("%c\n", *res[i]);
// 	return (0);
// }
