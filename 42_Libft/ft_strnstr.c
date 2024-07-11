/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:48:42 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/19 18:27:34 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

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

/*int	main(void)
{
	char needle [] = "aiguille";
	char straw [] = "c'est comme chercher une aiguille dans une botte de foin";
	size_t size = 50;
	printf("%s\n%s\n%s\n", needle, straw, ft_strnstr(straw, needle, size));
	return (0);
}*/
