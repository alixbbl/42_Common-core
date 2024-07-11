/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:13:43 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/07 16:28:12 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		a;
	void		*ptr;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	a = nmemb * size;
	if (a / nmemb != size)
		return (0);
	ptr = malloc(size * nmemb);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int	main(void)
{
	char *dest;
	dest = ft_calloc(12, 1);
	dest = malloc(12);
	write(1, dest, 12);
	write(1, "\r", 1);
	return(0);
}*/
