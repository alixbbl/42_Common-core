/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:03:11 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/17 10:12:55 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_of_3(t_block **stack_a)
{
	t_block	*tp;
	t_block	*lst;
	int		b;

	tp = *stack_a;
	lst = get_last_block(tp);
	b = tp->nxt->val;
	if (!stack_is_sorted(*stack_a))
	{
		if ((tp->val < lst->val) && (b < lst->val) && (tp->val > b))
			swap_a(stack_a);
		if ((tp->val > b) && (tp->val > lst->val) && (b < lst->val))
			rotate_a(stack_a);
		if ((tp->val < b) && (tp->val > lst->val) && (b > lst->val))
			reverse_rotate_a(stack_a);
		if ((tp->val > b) && (b > lst->val) && (tp->val > lst->val))
			swap_and_reverse_rotate(stack_a);
		if ((tp->val < b) && (tp->val < lst->val) && (b > lst->val))
			swap_and_rotate(stack_a);
	}
}

void	al_go_5(t_block **stack_a, t_block **stack_b, int size, int pos_low)
{
	while (size > 3)
	{
		if (pos_low == 2)
			swap_a(stack_a);
		else if (pos_low == 3)
		{
			rotate_a(stack_a);
			swap_a(stack_a);
		}
		else if (pos_low == 4 && size == 5)
		{
			reverse_rotate_a(stack_a);
			reverse_rotate_a(stack_a);
		}
		else if (pos_low == 5 || (pos_low == 4 && size == 4))
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
		size--;
		pos_low = get_position_lowest(*stack_a);
	}
}

void	algo_of_5(t_block **stack_a, t_block **stack_b)
{
	int		pos_low;
	int		size;

	size = sizing(*stack_a);
	pos_low = get_position_lowest(*stack_a);
	al_go_5(stack_a, stack_b, size, pos_low);
	algo_of_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
