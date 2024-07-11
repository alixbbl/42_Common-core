/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:43:46 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 13:15:10 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*cstr;

	cstr = (char *)str;
	len = ft_strlen(cstr);
	while (cstr[len] != c && len > 0)
	{
		len--;
	}
	if (cstr[len] == (char)c)
		return (cstr + len);
	return (NULL);
}

/*int	main(void)
{
	const char str[] = "abcdefghijkflm";
	const char c = 'f';
	char *p;
	p = ft_strrchr(str, c);
	printf("Pointeur a partir de %c is %s", c, p);
	return(0);
}*/
