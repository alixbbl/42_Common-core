/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:09:50 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 13:16:29 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

//fonction auxiliaire similaire a strchr.

int	ft_charset(char const *set, char c)
{
	size_t		i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

// fonction principale permet de trouver l'index des bornes start et end, 
//apres le trim.

char	*ft_strtrim(char const *src, char const *set)
{
	char		*dest;
	size_t		start;
	size_t		end;
	size_t		i;

	start = 0;
	while (src[start] && ft_charset(set, src[start]))
		start++;
	end = ft_strlen(src);
	while (end > start && ft_charset(set, src[end - 1]))
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char str[] = "aaabbcaabjghgjghgjhgabcbacab";
	char set[] = "abc";
	printf("%s\n%s", str, ft_strtrim(str, set));
	return (0);
}*/