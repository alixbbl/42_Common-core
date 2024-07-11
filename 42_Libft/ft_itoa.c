/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:59:46 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/26 13:43:36 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// penser a ajouter 1 a len si le nb est negatif pour le -.
int	ft_len_string(long nb)
{
	unsigned int	len;

	len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len += 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int numb)
{
	unsigned int	len;
	long			nb;
	char			*str;

	nb = numb;
	len = ft_len_string(nb);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[len] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}

/*int	main(int ac, char **av)
{
	int n = atoi(av[1]);
	int n2 = atoi(av[2]);

	printf ("Les nombres sont %d et %d\n", n ,n2);
	printf("Les char sont %s et %s\n", ft_itoa(n), ft_itoa(n2));
	return(0);
}
*/
