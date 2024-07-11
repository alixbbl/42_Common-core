/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:08:21 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 10:28:26 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *chain)
{
	while (chain)
	{
		if (!chain->next)
			return (chain);
		chain = chain->next;
	}
	return (chain);
}
/* Trouver le dernier maillon de la chaine, on avance dans les maillons, 
jusqu'a ce que la composante next du dernier pointeur soit NULL, 
on renvoie le pointeur sur cet element.*/