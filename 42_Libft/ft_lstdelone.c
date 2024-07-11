/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:07:33 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 10:18:51 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*si lst ou la fonction Delete n'existe pas, rien ne peut etre fait. 
Sinon, on efface le contenu de la structure avec Delete puis on free l'espace 
alloue en memoire.
*/
