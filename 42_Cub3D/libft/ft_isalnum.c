/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:31:33 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/17 16:24:41 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (8);
	if (c >= 48 && c <= 57)
		return (8);
	else
		return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		{
// 		printf("%d\n", isalnum(atoi(argv[1])));
// 		printf("%d", ft_isalnum(atoi(argv[1])));
// 		}
// 	return(0);
// }