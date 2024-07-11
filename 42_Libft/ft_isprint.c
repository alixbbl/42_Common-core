/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:13:28 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:20:28 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(char c)
{
	if ((c >= 32 && (c <= 126)))
		return (c);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isprint("\n"));
	printf("%d\n", ft_isprint(""));
	printf("%d\n", ft_isprint("hbhdfgdufhgbvdjfbg"));
}*/
