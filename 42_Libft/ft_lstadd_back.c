/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:59:07 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 10:27:26 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_chain;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_chain = ft_lstlast(*lst);
	last_chain->next = new;
}
/*on veut ajouter un nouveau maillon new a la fin de la chaine existante, il 
faut donc verifier l'existence des valeurs de **lst et *lst comme conditions 
d'entree, puis aller au bout de la chaine (on utilise du coup la fonction 
ft_lstlast), une fois identifie le dernier bloc last_chain, on fait pointer sur 
le new. Si la chaine est inexistante, seul le nouveau bloc existe.*/
