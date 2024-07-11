/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:07:53 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 16:51:03 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
			return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_memcmp("abcdefghijklm", "abcddfghijklm", 7));
	printf("%d\n", ft_memcmp("abcdefghijklm", "abcdefghijklm", 13));
	printf("%d\n", ft_memcmp("abcd", "abcd", 0));
	printf("%d\n", ft_memcmp("abcddfghijklm", "abcdefghijklm", 7));
	return (0);
}*/
