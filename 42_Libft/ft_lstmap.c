/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:08:11 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 12:13:17 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_chain;
	t_list	*new_chain;

	if (!f || !lst || !del)
		return (NULL);
	new_chain = NULL;
	while (lst)
	{
		first_chain = ft_lstnew(((*f)(lst->content)));
		if (!(first_chain))
		{
			ft_lstclear(&first_chain, del);
			return (NULL);
		}
		ft_lstadd_back(&new_chain, first_chain);
		lst = lst->next;
	}
	return (new_chain);
}
