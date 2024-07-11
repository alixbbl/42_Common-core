/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:00:31 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/21 13:27:22 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int numb, int fd)
{
	if (numb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (numb > 9)
	{
		ft_putnbr_fd(numb / 10, fd);
		ft_putnbr_fd(numb % 10, fd);
	}
	else if (numb < 0)
	{
		ft_putchar_fd('-', fd);
		numb *= -1;
		ft_putnbr_fd(numb, fd);
	}
	else
	{
		ft_putchar_fd(48 + numb, fd);
	}
	return ;
}

/*int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2, 1);
	write(1, "\n", 1);
}*/
