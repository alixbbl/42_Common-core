/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:06:28 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 16:45:17 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_block **pile_src, t_block **pile_dest)
{
	t_block	*temp;
	t_block	*chain;

	if (!*pile_src)
		return (-1);
	chain = (*pile_src)->nxt;
	temp = *pile_src;
	temp->nxt = *pile_dest;
	*pile_dest = temp;
	*pile_src = chain;
	return (0);
}

int	push_a(t_block **pile_a, t_block **pile_b)
{
	int	fd;

	if (push(pile_b, pile_a) == -1)
		return (-1);
	fd = 1;
	ft_putendl_fd("pa", fd);
	return (1);
}

int	push_b(t_block **pile_a, t_block **pile_b)
{
	int	fd;

	if (push(pile_a, pile_b) == -1)
		return (-1);
	fd = 1;
	ft_putendl_fd("pb", fd);
	return (1);
}

// int main(int ac, char ** ag)
// {
//     t_block *chain1 = create_stack(ac, ag);
//     t_block *chain2;
//     push(&chain1, &chain2);

//     while (chain1)
//     {
//         printf("%d\n", chain1->value);
//         chain1 = chain1->nxt;
//     }
//     write(1, "\n", 1);
//     while (chain2)
//     {
//         printf("%d\n", chain2->value);
//         chain2 = chain2->nxt;
//     }
// }
