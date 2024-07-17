/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:35:16 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 12:33:05 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst > src)
	{
		while (n > 0)
		{
			((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n -1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		{
// 		char	*p1;
// 		char	*p2;

// 		p1 = memmove(argv[1], argv[2], atoi(argv[3]));
// 		printf("true: %s\n", p1);
// 		p2 = ft_memmove(argv[1], argv[2], atoi(argv[3]));
// 		printf("mine: %s\n", p2);
// 		}
// 	return(0);
// }