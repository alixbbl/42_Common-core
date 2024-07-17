/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:00 by jarthaud          #+#    #+#             */
/*   Updated: 2023/10/16 14:47:26 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 4)
// 		{
// 		int	p1;
// 		int	p2;

// 		p1 = strncmp(argv[1], argv[2], atoi(argv[3]));
// 		printf("true: %d\n", p1);
// 		p2 = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
// 		printf("mine: %d\n", p2);
// 		}
// 	return(0);
// }