/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:27:35 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 13:21:35 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
	{
		c = c - 32;
	}
	return (c);
}

/*int main(void)
{
    int c = 118;
    printf("%d\n%d\n", c, ft_toupper(c));
    return(0);
}*/
