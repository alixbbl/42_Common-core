/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:24:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 17:12:43 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_lowest(t_block *stack)
{
	int		pos;
	t_block	*lowest;
	t_block	*current;

	pos = 1;
	lowest = find_lowest(stack);
	current = stack;
	while (current && current != lowest)
	{
		current = current->nxt;
		pos++;
	}
	return (pos);
}

t_block	*find_lowest(t_block *stack)
{
	t_block	*lowest;
	t_block	*current;

	lowest = stack;
	current = stack;
	while (current)
	{
		if (lowest->val > current->val)
			lowest = current;
		current = current->nxt;
	}
	return (lowest);
}

void	swap_and_rotate(t_block **stack)
{
	swap_a(stack);
	rotate_a(stack);
}

void	swap_and_reverse_rotate(t_block **stack)
{
	swap_a(stack);
	reverse_rotate_a(stack);
}
