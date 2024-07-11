/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:34 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:18:48 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*int	main(void)
{
	int	c = 42;
	int	d = 11;
	int	e = 89;
	printf("%d\n%d\n%d\n", ft_isascii(c), ft_isascii(d), ft_isascii(e));
	return(0);
}*/