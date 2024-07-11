/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:44:06 by alibourb          #+#    #+#             */
/*   Updated: 2023/01/10 15:54:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*out;

	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	out = malloc(sizeof(*out) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		out[j++] = str1[i++];
	j = 0;
	while (str2[j])
		out[i++] = str2[j++];
	out[i] = '\0';
	free(str1);
	return (out);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}
