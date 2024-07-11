/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:36:43 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:31:24 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;

	i = 0;
	if (!dest)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char src[] = "pas facile a capter ce bordel";
	char dest[] = "ABCD";
	size_t n = 8;
	printf("%s\n", dest);
	ft_memcpy(dest + 3, src, n);
	printf("%s\n", dest);
	return(0);
}*/
