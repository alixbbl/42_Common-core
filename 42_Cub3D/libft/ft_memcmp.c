/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:28 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 12:53:21 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	i = 0;
	ptrs1 = ((unsigned char *)s1);
	ptrs2 = ((unsigned char *)s2);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		{
// 		int	p1;
// 		int	p2;

// 		p1 = memcmp(argv[1], argv[2], atoi(argv[3]));
// 		printf("true: %d\n", p1);
// 		p2 = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
// 		printf("mine: %d\n", p2);
// 		}
// 	return(0);
// }