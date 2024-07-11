/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:07:59 by alibourb          #+#    #+#             */
/*   Updated: 2022/11/30 10:30:35 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/*on a declare "t_list", une variable structure de type "s_list", dont les 
variables composantes sont "void *content" et "struct s_list *next". 
Imbrication des maillons de type structures. 
On veut malloc et renvoyer le nouveau maillon t_list.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struct;

	new_struct = NULL;
	new_struct = (t_list *)malloc(sizeof(t_list));
	if (!new_struct)
		return (NULL);
	else
	{
		new_struct->content = content;
		new_struct->next = NULL;
	}
	return (new_struct);
}
// (*next_struct).next est l'autre syntaxe correcte
// les deux syntaxes sont equivalentes, mais la premiere est la plus usitee.
