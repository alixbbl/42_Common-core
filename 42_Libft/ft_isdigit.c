/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:55:11 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:19:39 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
	{
		return (c);
	}
	return (0);
}

/*int	main(void)
{
	int	c = 42;
	int	d = 11;
	int	e = 89;
	printf("%d\n%d\n%d\n", ft_isdigit(c), ft_isdigit(d), ft_isdigit(e));
	return(0);
}*/