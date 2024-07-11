/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:45 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 10:27:54 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start_del;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		start_del = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = start_del;
	}
	*lst = NULL;
}
/*
lst est le pointeur sur un element, del, adresse de la fonction Delete.
Meme usage que lstdelone mais les elements suivants lst sont tous supprimes 
et le pointeur du (nouveau) dernier element de la chaine est mis a NULL.
REVOIR **LST ET *LST, syntaxe.
*/
