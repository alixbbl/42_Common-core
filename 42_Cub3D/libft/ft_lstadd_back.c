/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:17:53 by jarthaud          #+#    #+#             */
/*   Updated: 2023/07/11 17:33:45 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add_last;

	if (!*lst)
	{
		*lst = new;
		return (NULL);
	}
	else
	{
		add_last = ft_lstlast(*lst);
		add_last->next = new;
	}
	return (*lst);
}

// int main(void)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = ft_lstnew("salut");
// 	b = ft_lstnew("ca va");
// 	ft_lstadd_back(&a, b);
// 	printf("%s\n", (char *)a->content);
// 	printf("%s\n", (char *)a->next->content);
// 	return (0);
// }