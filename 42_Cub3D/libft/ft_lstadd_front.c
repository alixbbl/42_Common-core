/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarthaud <jarthaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:39 by jarthaud          #+#    #+#             */
/*   Updated: 2022/11/23 15:01:42 by jarthaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = ft_lstnew("salut");
// 	b = ft_lstnew("ca va");
// 	ft_lstadd_front(&a, b);
// 	printf("%s\n", (char *)a->content);
// 	printf("%s\n", (char *)a->next->content);
// 	return (0);
// }