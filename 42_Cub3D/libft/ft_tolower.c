/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:23:49 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/16 14:59:39 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		{
// 		printf("%d\n", tolower(atoi(argv[1])));
// 		printf("%d", ft_tolower(atoi(argv[1])));
// 		}
// 	return(0);
// }