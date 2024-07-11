/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:29:04 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/07 17:42:46 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	unsigned long	i;

	i = 0;
	if (nbr >= 16)
		i += ft_putnbr_hex(nbr / 16, base);
	i += ft_putchar(base[nbr % 16]);
	return (i);
}
