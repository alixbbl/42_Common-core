/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:01:30 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/21 11:42:30 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*dest;

	if (!(str) || !(*f))
		return (NULL);
	len = ft_strlen(str);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = (f)(i, str[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
