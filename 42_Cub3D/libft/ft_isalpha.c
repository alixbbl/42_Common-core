/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:40:37 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 16:24:51 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c < 65 || ((c > 90) && (c < 97)) || c > 122)
		return (0);
	else
		return (1024);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		{
// 		printf("%d\n", isalpha(atoi(argv[1])));
// 		printf("%d", ft_isalpha(atoi(argv[1])));
// 		}
// 	return(0);
// }
