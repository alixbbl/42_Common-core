/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:32:15 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/24 12:22:49 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	newlist = (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, new);
		lst = lst->next;
	}
	return (newlist);
}

// int main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*c;

// 	a = ft_lstnew("salut");
// 	b = ft_lstnew("ca va");
// 	c = ft_lstnew("bien");
// 	ft_lstadd_back(&a, b);
// 	ft_lstadd_back(&b, c);
// 	printf("%s\n", (char *)ft_lstmap(a));
// 	return (0);
// }