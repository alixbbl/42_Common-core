/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:57:43 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/21 12:34:01 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_putnbr_uns(unsigned int numb)
{
	unsigned long	i;

	i = 0;
	if (numb == 2147483647)
	{
		write(1, "2147483647", 10);
		return (10);
	}
	if (numb > 9)
	{
		i += ft_putnbr(numb / 10);
		i += ft_putnbr(numb % 10);
	}
	else
		i += ft_putchar(48 + numb);
	return (i);
}
