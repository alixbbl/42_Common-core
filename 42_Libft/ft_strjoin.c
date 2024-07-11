/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:08:51 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/21 13:49:47 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_str1;
	unsigned int	len_str2;
	char			*out;

	if (!str1)
		return ((char *)str2);
	if (!str2)
		return ((char *)str1);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	out = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!(out))
		return (NULL);
	i = -1;
	while (str1[++i] && i < len_str1)
		out[i] = str1[i];
	j = -1;
	while (str2[++j] && j < len_str2)
		out[i + j] = (char)str2[j];
	out[i + j] = '\0';
	return (out);
}

/*int	main(void)
{
	char const str1[] = "abcdefghijklm";
	char const str2[] = "nopqrstuvwxyz";
	char *out;
	out = ft_strjoin(str1, str2);
	printf("%s\n", out);
	return(0);
}*/
