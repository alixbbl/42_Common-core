/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:09 by jarthaud          #+#    #+#             */
/*   Updated: 2023/07/24 14:48:11 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		{
// 		printf("%ld\n", strlen(argv[1]));
// 		printf("%ld", ft_strlen(argv[1]));
// 		}
// 	return(0);
// }