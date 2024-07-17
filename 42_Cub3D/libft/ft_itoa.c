/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:42:05 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/18 16:19:49 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size += 1;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_strrev(char *str, int size)
{
	int		i;
	char	tmp;

	i = 0;
	size--;
	while (i < (size - i))
	{
		tmp = str[size - i];
		str[size - i] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*res;
	int		size;

	nb = n;
	i = 1;
	size = (ft_size(nb) + 1);
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	res[0] = '\0';
	while (nb >= 10)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	res[i] = nb + 48;
	if (n < 0)
		res[i + 1] = '-';
	return (ft_strrev(res, size));
}

// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         char    *res;

//         res = ft_itoa(atoi(argv[1]));
//         printf("res final: %s\n", res);
//     }
//     return (0);
// }
