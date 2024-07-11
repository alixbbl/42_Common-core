/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:32:56 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 17:02:30 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sizing(t_block *lst)
{
	int	size;

	size = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->nxt;
		size++;
	}
	return (size);
}

t_block	*create_stack(int ac, char **argv)
{
	int		i;
	t_block	*chain;

	chain = NULL;
	i = 1;
	while (i < ac)
	{
		if (i == 1)
		{
			chain = new_block(ft_atol(argv[i]));
		}
		else
			add_block_at_back(&chain, new_block(ft_atol(argv[i])));
		i++;
	}
	return (chain);
}

int	stack_is_sorted(t_block *stack)
{
	while (stack->nxt)
	{
		if (stack->val > stack->nxt->val)
			return (0);
		stack = stack->nxt;
	}
	return (1);
}

int	median(t_block *stack)
{
	int	median;

	median = (sizing(stack) / 2) + (sizing(stack) % 2);
	return (median);
}

void	push_swap(t_block **stack_a, t_block **stack_b, int size_chain)
{
	if ((size_chain == 2) && (!stack_is_sorted(*stack_a)))
		swap_a(stack_a);
	else if ((size_chain == 3) && (!stack_is_sorted(*stack_a)))
		algo_of_3(stack_a);
	else if ((size_chain == 4 || size_chain == 5)
		&& (!stack_is_sorted(*stack_a)))
		algo_of_5(stack_a, stack_b);
	else if ((size_chain > 5) && (!stack_is_sorted(*stack_a)))
		big_sort(stack_a, stack_b);
}
