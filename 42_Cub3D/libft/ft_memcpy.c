/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:57 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 12:24:59 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		{
// 		char	*p1;
// 		char	*p2;

// 		p1 = memcpy(argv[1], argv[2], atoi(argv[3]));
// 		printf("true: %s\n", p1);
// 		p2 = ft_memcpy(argv[1], argv[2], atoi(argv[3]));
// 		printf("mine: %s\n", p2);
// 		}
// 	return (0);
// }