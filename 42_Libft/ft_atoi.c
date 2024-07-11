/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:41:07 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:12:45 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	char	*cstr;

	i = 0;
	sign = 1;
	result = 0;
	cstr = (char *)str;
	while (((cstr[i] <= 13 && cstr[i] >= 9)) || cstr[i] == ' ')
		i++;
	if (cstr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (cstr[i] == '+')
		i++;
	while ((cstr[i] >= '0' && cstr[i] <= '9') && cstr[i])
	{
		result *= 10;
		result = result + (cstr[i] - '0');
		i++;
	}
	return (sign * result);
}

/*int	main(void)
{
	printf("%d", ft_atoi("    -123uuu"));
	return (0);
}*/
