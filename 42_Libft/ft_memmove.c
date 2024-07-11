/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:49:31 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/19 15:56:26 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// size est le nombre d'octets a dupliquer
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		while (len > 0)
		{
			((char *)dest)[len - 1] = (((char *)src)[len - 1]);
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	unsigned char src[] = "pas facile a capter ce bordel";
	unsigned char dest[] = "ABCD";
	size_t n = 8;
	printf("%s\n", dest);
	ft_memmove(dest + 3, src, n);
	printf("%s\n", dest);
	return(0);
}*/
