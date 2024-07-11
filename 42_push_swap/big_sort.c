/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:49:25 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 16:38:51 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_block	*find_cheapest(t_block *stack_a, t_block *stack_b)
{
	t_block	*cheapest;
	t_block	*runner;
	int		moves_runner;
	int		moves_cheapest;

	cheapest = stack_a;
	runner = stack_a;
	moves_cheapest = counter(stack_a, stack_b, cheapest);
	while (runner)
	{
		moves_runner = counter(stack_a, stack_b, runner);
		if (moves_runner < moves_cheapest)
		{
			cheapest = runner;
			moves_cheapest = moves_runner;
		}
		runner = runner->nxt;
	}
	return (cheapest);
}

void	push_back_to_a(t_block **stack_a, t_block **stack_b)
{
	t_block	*block_b;
	t_block	*target;

	block_b = *stack_b;
	target = next_highest(*stack_a, block_b);
	while (*stack_a != target)
	{
		if (get_pos(*stack_a, target) <= (sizing(*stack_a) / 2)
			+ (sizing(*stack_a) % 2))
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
}

void	put_in_order(t_block **stack_a)
{
	t_block	*lowest_a;

	lowest_a = find_lowest(*stack_a);
	while (*stack_a != lowest_a)
	{
		if (get_pos(*stack_a, lowest_a) <= (sizing(*stack_a) / 2)
			+ (sizing(*stack_a) % 2))
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

void	big_sort(t_block **sa, t_block **sb)
{
	t_block	*cheap;
	t_block	*match;
	int		count_a;
	int		count_b;

	push_b(sa, sb);
	push_b(sa, sb);
	while (sizing(*sa) > 3)
	{
		cheap = find_cheapest(*sa, *sb);
		match = next_lowest(*sb, cheap);
		count_a = to_top(*sa, cheap);
		count_b = to_top(*sb, match);
		if (((count_a && count_b) && (get_pos(*sa, cheap) <= median(*sa)))
			&& (get_pos(*sb, match) <= median(*sb)))
			push_to_b_rr(sa, sb, cheap, match);
		else if (((count_a && count_b) && (get_pos(*sa, cheap) > median(*sa)))
			&& (get_pos(*sb, match) > median(*sb)))
			push_to_b_rrr(sa, sb, cheap, match);
		else
			push_to_b_normal(sa, sb, cheap, match);
	}
	big_sort_ending(sa, sb);
}

void	big_sort_ending(t_block **stack_a, t_block **stack_b)
{
	algo_of_3(stack_a);
	while (sizing(*stack_b) > 0)
		push_back_to_a(stack_a, stack_b);
	put_in_order(stack_a);
}
