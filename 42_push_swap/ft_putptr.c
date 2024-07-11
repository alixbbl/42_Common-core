/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:06:21 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/21 12:34:24 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_ptr(int c)
{
	write(1, &c, 1);
}

unsigned int	ft_hexa(unsigned long nbr)
{
	unsigned long	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

void	ft_putptr_hex(unsigned long l_ptr, char *base)
{
	if (l_ptr >= 16)
		ft_putptr_hex(l_ptr / 16, base);
	ft_putchar_ptr(base[l_ptr % 16]);
}

unsigned int	ft_putptr(void *ptr)
{
	unsigned long	l_ptr;
	unsigned long	i;
	char			*base;

	base = "0123456789abcdef";
	l_ptr = (unsigned long)ptr;
	if (!ptr)
		i = write(1, "(nil)", 5);
	else
	{
		i = ft_hexa(l_ptr);
		i += write(1, "0x", 2);
		ft_putptr_hex(l_ptr, base);
	}
	return (i);
}
