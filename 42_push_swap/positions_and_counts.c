/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_and_counts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:55:15 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/17 10:34:25 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_block *stack, t_block *current)
{
	int	pos;

	pos = 0;
	while (stack != current)
	{
		pos++;
		stack = stack->nxt;
	}
	return (pos);
}

int	to_top(t_block *stack, t_block *chain)
{
	int	position;
	int	size_chain;
	int	count;

	position = get_pos(stack, chain);
	size_chain = sizing(stack);
	count = 0;
	if (size_chain % 2 == 0)
	{
		if (position <= (size_chain / 2))
			count = position;
		else
			count = size_chain - position;
	}
	else if (size_chain % 2 == 1)
	{
		if (position < (size_chain / 2) + 1)
			count = position;
		else if (position >= (size_chain / 2) + 1)
			count = size_chain - position;
	}
	return (count);
}

int	same_side(t_block *stack_a, t_block *stack_b, t_block *cheapest,
	t_block *match)
{
	int	median_a;
	int	median_b;

	match = next_lowest(stack_b, cheapest);
	median_a = (sizing(stack_a) / 2) + (sizing(stack_a) % 2);
	median_b = (sizing(stack_b) / 2) + (sizing(stack_b) % 2);
	if ((((get_pos(stack_a, cheapest) < median_a)
				&& (get_pos(stack_b, match) < median_b)))
		|| ((get_pos(stack_a, cheapest) >= median_a)
			&& (get_pos(stack_b, match) >= median_b)))
		return (1);
	return (0);
}

int	counter(t_block *stack_a, t_block *stack_b, t_block *cheapest)
{
	int		count_total;
	t_block	*match;

	match = next_lowest(stack_b, cheapest);
	if ((same_side(stack_a, stack_b, cheapest, match))
		&& (to_top(stack_a, cheapest) >= to_top(stack_b, match)))
		count_total = (to_top(stack_a, cheapest));
	else if ((same_side(stack_a, stack_b, cheapest, match))
		&& (to_top(stack_a, cheapest) < to_top(stack_b, match)))
		count_total = (to_top(stack_b, match));
	else
		count_total = to_top(stack_a, cheapest) + to_top(stack_b, match);
	return (count_total);
}

t_block	*find_highest(t_block *stack)
{
	t_block	*highest;
	t_block	*current;

	highest = stack;
	current = stack;
	while (current)
	{
		if (highest->val < current->val)
			highest = current;
		current = current->nxt;
	}
	return (highest);
}
