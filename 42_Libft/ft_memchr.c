/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:32:56 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:29:58 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;

	csrc = (unsigned char *)src;
	if (!src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (csrc[i] == (unsigned char)c)
			return ((void *)src + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	unsigned char src[] = "abcdefghijklm";
	unsigned char c = 'f';
	unsigned char *ptr_ret;

	ptr_ret = ft_memchr(src, c, 14);
	printf("Le pointeur retour apres %c est %s", c, ptr_ret);
	return(0);
}*/
