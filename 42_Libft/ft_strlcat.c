/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:29:13 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/18 13:03:05 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*on ajoute les char de src a la fin de dest en ecrasant l'octet nul final,
mais uniquement dans la limite du buffer impose. Par consequent, ce qu'il reste 
pour ecrire src, c'est la difference entre size et la longueur de dest (len_dest)
moins 1 pour l'octet nul.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_max;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_max = ft_strlen(src) + len_dest;
	if (!size && !dest && !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	if (size < len_dest)
		return (ft_strlen(src) + size);
	i = 0;
	while (((len_dest + i) < size - 1) && (src[i] != '\0'))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_max);
}

/*int	main(void)
{
	const char	src[] = "hello la famille";
	char		dest[] = "ta gueule";
	size_t		size = 18;
	printf("%ld\n", ft_strlcat(dest, src, size));
	return(0);

}*/
