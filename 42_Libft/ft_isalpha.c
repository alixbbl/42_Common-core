/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:37 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:17:36 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return (c);
	else
		return (0);
}

/*int	main(void)
{
	int	c = 42;
	int	d = 11;
	int	e = 89;
	printf("%d\n%d\n%d\n", ft_isalpha(c), ft_isalpha(d), ft_isalpha(e));
	return(0);
}*/
