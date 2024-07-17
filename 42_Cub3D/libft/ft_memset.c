/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:33 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 11:22:16 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		{
// 		char	*p1;

// 		printf("%s\n", argv[1]);
// 		p1 = ft_memset(argv[1], (int)*argv[2], atoi(argv[3]));
// 		printf("good: %s\n", p1);
// 		}
// 	return(0);
// }