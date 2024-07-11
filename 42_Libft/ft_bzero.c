/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:54:16 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:13:59 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ecrire des octets de valeur \0 dans un bloc pointe.
#include"libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	if (!str || !n)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	unsigned char str[] = "hdfbladhbvlbvdjbv";
	printf("Avant fonction %s\n", str);
	ft_bzero(str + 4, 5*sizeof(unsigned char));
	printf("Apres fonction %s\n", str);
	return(0);	
}*/
