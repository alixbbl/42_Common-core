/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:27:52 by jarthaud          #+#    #+#             */
/*   Updated: 2023/08/18 15:16:51 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ((char)c))
			return ((char *)s + i);
		i++;
	}
	if ((char)s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		char	*p1;
// 		char	*p2;

// 		p1 = strchr(argv[1], (int)*argv[2]);
// 		p2 = ft_strchr(argv[1], (int)*argv[2]);
// 		printf("true: %s\n", p1);
// 		printf("mine: %s\n", p2);
// 	}
// 	return (0);
// }
