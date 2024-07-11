/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:27 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 10:16:40 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

/* on veut ajouter un maillon directement apres le premier bloc de la chaine, 
on verifie donc l'existence de **lst et *lst. Ensuite, on "connecte" la variable 
composante next du nouveau bloc avec celui precedent. Si **lst n'existe pas, 
new devient le premier element de la chaine.*/
