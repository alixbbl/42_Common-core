/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:45:16 by jarthaud          #+#    #+#             */
/*   Updated: 2023/11/09 17:44:38 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	countw;
	int	i;

	i = 0;
	countw = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			countw++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (countw);
}

static int	ft_wordsize(char const *s, char c, int pos)
{
	int	wsize;

	wsize = 0;
	while (s[pos] != c && s[pos])
	{
		wsize++;
		pos++;
	}
	return (wsize);
}

static void	*ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		j;
	char	**res;

	res = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	index = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			res[index] = ft_substr(s, j, (ft_wordsize(s, c, j)));
			if (!res[index])
				ft_free(res, index - 1);
			j += (ft_wordsize(s, c, j));
			index++;
		}
		else
			j++;
	}
	res[index] = 0;
	return (res);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
//     {
//         char    **res;
//         int i;

//         i = 0;
//         res = ft_split(argv[1], ' ');
//         while (i < (ft_countwords(argv[1], ' ')))
//         {
//             ft_putstr_fd(res[i], 1);
//             write(1, "\n", 1);
//             i++;
//         }
//         write(1, &res[i], 1);
//     }
//     return (0);
// }
