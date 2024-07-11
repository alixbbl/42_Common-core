/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:24:41 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 12:52:24 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//on veut retourner la copie de la source, mais avec malloc.
#include"libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] && (i < len))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(int ac, char **ag)
{
	(void)ac;
	(void)ag;
	char *dest;
	char src[] = "coucou";
	dest = ft_strdup(src);
	printf("%s", dest);
	return (0);
}*/
