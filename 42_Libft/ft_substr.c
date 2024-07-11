/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:02:28 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/26 13:53:52 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	i;
	size_t			len_to_mal;

	if (!src)
		return (NULL);
	len_to_mal = ft_strlen(src) - start;
	if (len_to_mal > len)
		len_to_mal = len;
	if (ft_strlen(src) < start)
		len_to_mal = 0;
	out = (char *)malloc(sizeof(*out) * (len_to_mal + 1));
	if (!out)
		return (NULL);
	out[0] = '\0';
	if (ft_strlen(src) < start)
		return (out);
	i = 0;
	while (i < len && src[start + i])
	{
		out[i] = src[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*int	main(void)
{
	char const src[] = "abcdefghijklm";
	char *out;
	unsigned int start = 3;
	size_t len = 5;
	out = ft_substr(src, start, len);
	printf("%s\n", out);
	return(0);
}

int	main(void)
{
	char const src[] = "abcdefghijklm";
	char *out;
	unsigned int start = 0;
	size_t len = 5;
	out = ft_substr(src, start, len);
	printf("%s\n", out);
	return(0);
}*/
