/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:43:46 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 19:18:46 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (NULL);
}

/*int	main(void)
{
    const char str[] = "abcdefghijklm";
    const char c = 'f';
    char *p;
    p = ft_strchr(str, c);
    printf("Pointeur a partir de %c is %s", c, p);
    return(0);
}*/
