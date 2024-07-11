/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:11:36 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 13:04:18 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*on essaye de copier (size - 1) caracteres de src dans le buffer, mais valeur
renvoyee est toujours celle de la chaine quon veut copier
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (!src || !dest)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}

/*int	main(void)
{
	const char src[] = "abcdefghijklm";
	char dest[] = "oooooo";
	size_t size = 20;
	printf("%s\n%s\n", dest, src);
	ft_strlcpy(dest, src, size);
	printf("%s\n%s\n%ld\n", dest, src, ft_strlcpy(dest, src, size));
	return (0);
}*/
