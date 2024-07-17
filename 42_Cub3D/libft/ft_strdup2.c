/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:59:12 by jarthaud          #+#    #+#             */
/*   Updated: 2023/07/25 11:28:27 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	j = 0;
	while (s[i++])
		j++;
	dst = malloc(sizeof(char) * (j + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i])
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}
