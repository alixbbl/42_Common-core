/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:06:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 16:49:10 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_block **chain)
{
	t_block	*top;
	t_block	*back;

	if (!*chain || !(*chain)->nxt)
		return (-1);
	top = *chain;
	back = get_last_block(top);
	*chain = top->nxt;
	top->nxt = NULL;
	back->nxt = top;
	return (0);
}

int	rotate_a(t_block **pile_a)
{
	int	fd;

	fd = 1;
	if (rotate(pile_a) == -1)
		return (-1);
	ft_putendl_fd("ra", fd);
	return (1);
}

int	rotate_b(t_block **pile_b)
{
	int	fd;

	fd = 1;
	if (rotate(pile_b) == -1)
		return (-1);
	ft_putendl_fd("rb", fd);
	return (1);
}

int	rotate_r(t_block **pile_a, t_block **pile_b)
{
	int	fd;

	rotate(pile_a);
	rotate(pile_b);
	fd = 1;
	ft_putendl_fd("rr", fd);
	return (1);
}

// int main(int ac, char ** ag)
// {
//      s_block *chain1 = create_stack(ac, ag);
// 	    s_block *chain2 = chain1;

//     while (chain1)
//     {
//         printf("%d\n", chain1->val);
//         chain1 = chain1->nxt;
//     }
//     chain1 = chain2;
//     rotate(&chain1);
//     write(1, "\n", 1);
//     while (chain1)
//     {
//         printf("%d\n", chain1->val);
//         chain1 = chain1->nxt;
//     }
// }
