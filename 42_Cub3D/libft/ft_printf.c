/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:41:21 by jarthaud          #+#    #+#             */
/*   Updated: 2023/02/09 17:56:29 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert(va_list args, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		i += ft_putptr(va_arg(args, unsigned long long), 'x');
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		i += ft_putunbr(va_arg(args, unsigned int));
	if (c == 'x')
		i += ft_puthexa(va_arg(args, unsigned int), 'x');
	if (c == 'X')
		i += ft_puthexa(va_arg(args, unsigned int), 'X');
	if (c == '%')
		i += ft_putpercent();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_convert(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char	*to_print;
// 	// char	to_print3;
// 	// int	to_print2;
// 	unsigned int	moi;
// 	unsigned int	vraie;

// 	to_print = "";
// 	to_print2 = 0;
// 	// to_print2 = 125632;
// 	vraie = printf("printf true: %s\n", to_print);
// 	printf("vraie valeur: %d\n", vraie);
// 	moi = ft_printf("printf mine: %s\n", to_print);
// 	printf("ma valeur: %d", moi);
// 	return (0);
// }
