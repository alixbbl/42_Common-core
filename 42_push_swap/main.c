/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:03:11 by alibourb          #+#    #+#             */
/*   Updated: 2023/04/07 10:40:02 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_block **stack)
{
	t_block	*temp;

	temp = *stack;
	if (!(*stack))
		return ;
	while (*stack)
	{
		ft_printf("  %d\n", (*stack)->val);
		*stack = (*stack)->nxt;
	}
	*stack = temp;
}

void	free_stack(t_block **stack)
{
	t_block	*current;
	t_block	*next;

	current = *stack;
	if (*stack == NULL)
		return ;
	*stack = NULL;
	while (current != NULL)
	{
		next = current->nxt;
		free(current);
		current = next;
	}
}

int	main(int ac, char **ag)
{
	t_block	*stack_a;
	t_block	*stack_b;
	int		size_chain;

	if (ac < 2)
		return (0);
	if (!parsing(ac, ag))
	{
		ft_putstr("Error\n");
		return (0);
	}
	stack_a = create_stack(ac, ag);
	stack_b = NULL;
	size_chain = sizing(stack_a);
	if (stack_is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	push_swap(&stack_a, &stack_b, size_chain);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
