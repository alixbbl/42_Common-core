/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:44:10 by jarthaud          #+#    #+#             */
/*   Updated: 2023/08/18 14:11:21 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	if (!src || !dst)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	srclen = ft_strlen(src);
	return (srclen);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		long	p1;

// 		p1 = strlcpy(argv[1], argv[2], atoi(argv[3]));
// 		printf("true : %ld\n", p1);
// 		printf("dst true: %s\n", argv[1]);
// 		printf("src true: %s\n", argv[2]);
// 	}
// 	return (0);
// }
