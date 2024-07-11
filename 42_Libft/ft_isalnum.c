/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:37 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:16:50 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))
		|| ((c >= '0') && (c <= '9')))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	c = 42;
	int	d = 11;
	int	e = 89;
	printf("%d\n%d\n%d\n", ft_isalnum(c), ft_isalnum(d), ft_isalnum(e));
	return(0);
}*/
