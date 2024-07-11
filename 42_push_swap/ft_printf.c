/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:29:46 by alibourb          #+#    #+#             */
/*   Updated: 2022/12/09 16:41:01 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_print_arg(const char c, va_list ap)
{
	unsigned int	i;

	i = 0;
	if (c == '%')
		i += ft_putchar('%');
	else if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr_print(va_arg(ap, char *));
	else if (c == 'p')
		i += (ft_putptr((va_arg(ap, void *))));
	else if ((c == 'd') || (c == 'i'))
		i += (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		i += ft_putnbr_uns(va_arg(ap, unsigned int));
	else if ((c == 'x') || (c == 'X'))
	{
		if (c == 'x')
			i += ft_putnbr_hex((va_arg(ap, unsigned int)), "0123456789abcdef");
		else if (c == 'X')
			i += ft_putnbr_hex((va_arg(ap, unsigned int)), "0123456789ABCDEF");
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_print_arg(str[i + 1], ap);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
