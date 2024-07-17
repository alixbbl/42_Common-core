/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:22:20 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/28 11:49:11 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checktrim(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dst;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_checktrim(set, s1[start]) == 1 && start <= end)
		start++;
	while (ft_checktrim(set, s1[end]) == 1 && end >= start)
		end--;
	i = 0;
	dst = malloc(sizeof(char) * (end - start + 1) + 1);
	if (!dst)
		return (NULL);
	while (i <= (end - start))
	{
		dst[i] = s1[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// int main(int argc, char **argv)
// {
//     if (argc == 3)
//     {
//         char    *p1;

//         p1 = ft_strtrim(argv[1], argv[2]);
//         printf("mine: %s\n", p1);
//     }
//     return (0);
// }
