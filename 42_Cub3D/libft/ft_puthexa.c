/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:11:01 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/09 17:56:41 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_puthexa(unsigned long long n, char c)
{
	unsigned int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_puthexa((n / 16), c);
		i += ft_puthexa((n % 16), c);
	}
	else
	{	
		if (n < 10)
		{
			i += ft_putnbr(n + 0);
		}
		else
		{
			if (c == 'x')
				i += ft_putchar(n + 'a' - 10);
			if (c == 'X')
				i += ft_putchar(n + 'A' - 10);
		}
	}
	return (i);
}
