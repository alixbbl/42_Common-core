/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:37:49 by alibourb          #+#    #+#             */
/*   Updated: 2023/05/09 11:27:32 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tabs(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(char *str, char *to_find, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] && i < size)
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] && to_find[j]
			&& (i + j < size))
			j++;
		if (((char *)to_find)[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_str1;
	unsigned int	len_str2;
	char			*out;

	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	out = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (str1[++i] && i < len_str1)
		out[i] = str1[i];
	j = -1;
	while (str2[++j] && j < len_str2)
		out[i + j] = str2[j];
	out[i + j] = '\0';
	return (out);
}
