/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:02:03 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/18 14:26:30 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] && s1[i + j] && s2[j] == s1[j + i] && (i + j) < len)
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}

// int	 main(int argc, char **argv)
// {
// 	if (argc == 4)
// 	{
// 		char	*p1;
// 		char	*p2;

// 		p1 = strnstr(argv[1], argv[2], atoi(argv[3]));
// 		p2 = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
// 		printf("%s\n", p1);
// 		printf("%s", p2);
// 	}
// 	return (0);
// }
