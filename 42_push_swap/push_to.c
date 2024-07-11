/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:48:49 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/17 09:52:57 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_block	*next_lowest(t_block *stack_b, t_block *cheapest)
{
	t_block	*next_lowest;
	t_block	*run_b;

	run_b = stack_b;
	if (cheapest->val < find_lowest(stack_b)->val
		|| cheapest->val > find_highest(stack_b)->val)
		return (find_highest(stack_b));
	next_lowest = find_lowest(stack_b);
	while (run_b)
	{
		if (run_b->val > next_lowest->val && run_b->val
			< cheapest->val)
			next_lowest = run_b;
		run_b = run_b->nxt;
	}
	return (next_lowest);
}

t_block	*next_highest(t_block *stack_a, t_block *block_b)
{
	t_block	*next_highest;
	t_block	*run_a;

	run_a = stack_a;
	if (block_b->val > find_highest(stack_a)->val
		|| block_b->val < find_lowest(stack_a)->val)
		return (find_lowest(stack_a));
	next_highest = find_highest(stack_a);
	while (run_a)
	{
		if (run_a->val < next_highest->val && run_a->val > block_b->val)
			next_highest = run_a;
		run_a = run_a->nxt;
	}
	return (next_highest);
}

void	push_to_b_normal(t_block **stack_a, t_block **stack_b,
	t_block *cheapest, t_block *match)
{
	if (get_pos(*stack_a, cheapest) <= ((sizing(*stack_a) / 2)
			+ (sizing(*stack_a) % 2)))
	{
		while (get_pos(*stack_a, cheapest))
			rotate_a(stack_a);
	}
	else if (get_pos(*stack_a, cheapest) > ((sizing(*stack_a) / 2)
			+ (sizing(*stack_a) % 2)))
	{
		while (get_pos(*stack_a, cheapest))
			reverse_rotate_a(stack_a);
	}
	if (get_pos(*stack_b, match) > ((sizing(*stack_b) / 2)
			+ (sizing(*stack_b) % 2)))
	{
		while (get_pos(*stack_b, match))
			reverse_rotate_b(stack_b);
	}
	else if (get_pos(*stack_b, match) <= ((sizing(*stack_b) / 2)
			+ (sizing(*stack_b) % 2)))
	{
		while (get_pos(*stack_b, match))
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

void	push_to_b_rr(t_block **stack_a, t_block **stack_b,
	t_block *cheapest, t_block *match)
{
	int	count_a;
	int	count_b;

	count_a = to_top(*stack_a, cheapest);
	count_b = to_top(*stack_b, match);
	if ((count_a > 0) && (count_b > 0) && (count_a > count_b))
	{
		while (get_pos(*stack_b, match))
			rotate_r(stack_a, stack_b);
		while (get_pos(*stack_a, cheapest))
			rotate_a(stack_a);
	}
	else if ((count_a > 0) && (count_b > 0) && (count_a < count_b))
	{
		while (get_pos(*stack_a, cheapest))
			rotate_r(stack_a, stack_b);
		while (get_pos(*stack_b, match))
			rotate_b(stack_b);
	}
	else if ((count_a > 0) && (count_b > 0) && (count_a == count_b))
	{
		while (get_pos(*stack_a, cheapest) && get_pos(*stack_b, match))
			rotate_r(stack_a, stack_b);
	}
	push_b(stack_a, stack_b);
}

void	push_to_b_rrr(t_block **stack_a, t_block **stack_b,
	t_block *cheapest, t_block *match)
{
	int	count_a;
	int	count_b;

	count_a = to_top(*stack_a, cheapest);
	count_b = to_top(*stack_b, match);
	if ((count_a > 0) && (count_b > 0) && (count_a > count_b))
	{
		while (get_pos(*stack_b, match))
			reverse_rotate_r(stack_a, stack_b);
		while (get_pos(*stack_a, cheapest))
			reverse_rotate_a(stack_a);
	}
	else if ((count_a > 0) && (count_b > 0) && (count_a < count_b))
	{
		while (get_pos(*stack_a, cheapest))
			reverse_rotate_r(stack_a, stack_b);
		while (get_pos(*stack_b, match))
			reverse_rotate_b(stack_b);
	}
	else if ((count_a > 0) && (count_b > 0) && (count_a == count_b))
	{
		while ((get_pos(*stack_a, cheapest) && get_pos(*stack_b, match)))
			reverse_rotate_r(stack_a, stack_b);
	}
	push_b(stack_a, stack_b);
}
