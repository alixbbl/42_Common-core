/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:36:43 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:42:06 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)str)[i] = (char)c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	unsigned char str[] = "Pas facile a comprendre ce truc.";
	printf("Avant ft_memset exemple vaut %s\n", str);
	ft_memset(str + 5, '.', 7*sizeof(unsigned char));
	printf("Apres ft_memset exemple vaut %s\n", str);
	return(0);
}*/
