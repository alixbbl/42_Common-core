/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:56:20 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/09 16:41:43 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int numb)
{
	unsigned long	i;

	i = 0;
	if (numb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (numb > 9)
	{
		i += ft_putnbr(numb / 10);
		i += ft_putnbr(numb % 10);
	}
	else if (numb < 0)
	{
		i += ft_putchar('-');
		numb *= -1;
		i += ft_putnbr(numb);
	}
	else
		i += ft_putchar(48 + numb);
	return (i);
}
