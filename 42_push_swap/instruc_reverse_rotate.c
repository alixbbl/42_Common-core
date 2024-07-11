/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:06:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 16:53:54 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_block **chain)
{
	t_block	*top;
	t_block	*back;

	if (!*chain || !(*chain)->nxt)
		return (-1);
	top = *chain;
	back = get_last_block(top);
	while (top)
	{
		if (top->nxt->nxt == NULL)
		{
			top->nxt = NULL;
			break ;
		}
		top = top->nxt;
	}
	back->nxt = *chain;
	*chain = back;
	return (0);
}

int	reverse_rotate_a(t_block **pile_a)
{
	int	fd;

	fd = 1;
	if (reverse_rotate(pile_a) == -1)
		return (-1);
	ft_putendl_fd("rra", fd);
	return (1);
}

int	reverse_rotate_b(t_block **pile_b)
{
	int	fd;

	fd = 1;
	if (reverse_rotate(pile_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", fd);
	return (1);
}

int	reverse_rotate_r(t_block **pile_a, t_block **pile_b)
{
	int	fd;

	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	fd = 1;
	ft_putendl_fd("rrr", fd);
	return (1);
}

// int main(int ac, char ** ag)
// {
//     t_block *chain1 = create_stack(ac, ag);
// 	t_block *chain2 = chain1;

//     while (chain1)
//     {
//         printf("%d\n", chain1->val);
//         chain1 = chain1->nxt;
//     }
//     chain1 = chain2;
//     reverse_rotate(&chain1);
//     write(1, "\n", 1);
//     while (chain1)
//     {
//         printf("%d\n", chain1->val);
//         chain1 = chain1->nxt;
//     }
// }
