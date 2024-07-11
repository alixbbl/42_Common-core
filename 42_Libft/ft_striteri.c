/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:01:08 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:56:46 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if ((str && *f))
	{
		while (str[i])
		{
			(f)(i, &str[i]);
			i++;
		}
	}
}

/*int     main(void)
{
    unsigned int i = 0;
    char str[] = "coucou";
    printf("%s\n", str);
    ft_striteri(str, upchar(i, str));
    printf("%s\n", str);
    return(0);
}*/
