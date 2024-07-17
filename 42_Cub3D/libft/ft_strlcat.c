/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:55:21 by jarthaud          #+#    #+#             */
/*   Updated: 2023/10/04 11:06:10 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	d_len;
	size_t	max_len;

	if (!dst && !src)
		return (NULL);
	d_len = ft_strlen(dst);
	max_len = ft_strlen(src) + d_len;
	i = 0;
	while (src[i] != '\0' && i < max_len)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	max_len;

	if (!size && !dst && !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	max_len = ft_strlen(src) + d_len;
	if (size < d_len)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (max_len);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		printf("true : %ld\n", strlcat(argv[1], argv[2], atoi(argv[3])));
// 		printf("dst true: %s\n", argv[1]);
// 		printf("src true: %s\n", argv[2]);
// 	}
// 	return (0);
// }
