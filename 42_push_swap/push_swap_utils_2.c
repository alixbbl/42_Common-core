/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:24:54 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/16 17:12:43 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

t_block	*new_block(int value)
{
	t_block	*new_struct;

	new_struct = NULL;
	new_struct = (t_block *)malloc(sizeof(t_block));
	if (!new_struct)
		return (NULL);
	else
	{
		new_struct->val = value;
		new_struct->nxt = NULL;
	}
	return (new_struct);
}

t_block	*get_last_block(t_block *lst)
{
	while (lst)
	{
		if (!lst->nxt)
			return (lst);
		lst = lst->nxt;
	}
	return (lst);
}

void	add_block_at_back(t_block **lst, t_block *new_block)
{
	t_block	*last_block;

	if (!*lst)
	{
		*lst = new_block;
		return ;
	}
	last_block = get_last_block(*lst);
	last_block->nxt = new_block;
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (((str[i] <= 13 && str[i] >= 9))
		|| (str[i] == ' ') || str[i] == '0')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
