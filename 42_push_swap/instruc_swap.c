/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:06:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 16:57:13 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_block **chain)
{
	t_block	*temp;

	if (!*chain || !(*chain)->nxt)
		return (-1);
	temp = (*chain)->nxt;
	(*chain)->nxt = temp->nxt;
	temp->nxt = *chain;
	*chain = temp;
	return (0);
}

int	swap_a(t_block **pile_a)
{
	int	fd;

	fd = 1;
	if (swap(pile_a) == -1)
		return (-1);
	ft_putendl_fd("sa", fd);
	return (1);
}

int	swap_b(t_block **pile_b)
{
	int	fd;

	fd = 1;
	if (swap(pile_b) == -1)
		return (-1);
	ft_putendl_fd("sb", fd);
	return (1);
}

int	swap_s(t_block **pile_a, t_block **pile_b)
{
	int	fd;

	swap(pile_a);
	swap(pile_b);
	fd = 1;
	ft_putendl_fd("ss", fd);
	return (1);
}

// int main(int ac, char ** ag)
// {
//     t_block *chain1 = create_stack(ac, ag);
// 	   t_block *chain2 = chain1;

//     while (chain1)
//     {
//         printf("%d\n", chain1->val);
//         chain1 = chain1->nxt;
//     }
//     chain1 = chain2;
//     swap(&chain1);
//     while (chain1)
//     {
//         printf("%d\n", chain1->val);
//         chain1 = chain1->nxt;
//     }
// }
