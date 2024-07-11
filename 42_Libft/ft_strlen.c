/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:13:42 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 13:05:21 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;
	char	*ptr;

	if (!str)
		return (0);
	ptr = (char *)str;
	len = 0;
	while (ptr[len])
		len++;
	return (len);
}

/*int	main(void)
{
	printf("%ld", ft_strlen("ok les fweres"));
	return (0);
}*/
