/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:09 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 16:25:10 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		{
// 		printf("%d\n", isprint(atoi(argv[1])));
// 		printf("%d", ft_isprint(atoi(argv[1])));
// 		}
// 	return(0);
// }