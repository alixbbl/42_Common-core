/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:46 by jarthaud          #+#    #+#             */
/*   Updated: 2023/07/27 18:07:00 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mallocone(void)
{
	char	*dst;

	dst = malloc(sizeof(char) * 1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_mallocone());
	i = -1;
	if (len <= ft_strlen(s) - start)
	{
		dst = malloc(sizeof(char) * (len + 1));
		if (!dst)
			return (NULL);
		while (++i < len)
			dst[i] = s[start + i];
		dst[i] = '\0';
	}
	else
	{
		dst = malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
		if (!dst)
			return (NULL);
		while (++i < (ft_strlen(s) - start))
			dst[i] = s[start + i];
		dst[i] = '\0';
	}
	return (dst);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char	*res;

// 		res = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
// 		printf("%s\n", res);
// 	}
// 	return (0);
// }
