/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:21:02 by alibourb          #+#    #+#             */
/*   Updated: 2023/02/23 10:55:45 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct t_block
{
	int				val;
	struct t_block	*nxt;
}				t_block;

char			*put_line(const char *str, char c);
unsigned int	ft_hexa(unsigned long nbr);
unsigned int	ft_putptr(void *ptr);

unsigned int	ft_putnbr_uns(unsigned int numb);
unsigned int	ft_putnbr_hex(unsigned int nbr, char *base);
unsigned int	ft_print_arg(const char c, va_list ap);
int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_putstr_print(char *str);
int				ft_putnbr(int numb);
int				ft_nbrlen(char *numb);
int				ft_check_int(char *argv);
int				check_numb(char *argv);
int				check_double(int ac, int *argv);
int				sizing(t_block *lst);
int				swap(t_block **chain);
int				swap_a(t_block **pile_a);
int				swap_b(t_block **pile_b);
int				swap_s(t_block **pile_a, t_block **pile_b);
int				push(t_block **pile_src, t_block **pile_dest);
int				push_a(t_block **pile_a, t_block **pile_b);
int				push_b(t_block **pile_a, t_block **pile_b);
int				rotate(t_block **chain);
int				rotate_a(t_block **pile_a);
int				rotate_b(t_block **pile_b);
int				rotate_r(t_block **pile_a, t_block **pile_b);
int				reverse_rotate(t_block **chain);
int				reverse_rotate_a(t_block **pile_a);
int				reverse_rotate_b(t_block **pile_b);
int				reverse_rotate_r(t_block **pile_a, t_block **pile_b);
int				parsing(int ac, char **argv);
int				stack_is_sorted(t_block *stack);
int				get_pos(t_block *stack, t_block *current);
int				get_position_lowest(t_block *stack);
int				position_of_match(t_block *stack_b, t_block *match_of_a);
int				position_of_cheapest(t_block *stack_a, t_block *cheapest);
int				counter(t_block *stack_a, t_block *stack_b, t_block *chain);
int				to_top(t_block *stack, t_block *current);
int				same_side(t_block *stack_a, t_block *stack_b, \
				t_block *cheapest, t_block *match);
int				median(t_block *stack);
long			ft_atol(char *str);
t_block			*new_block(int value);
t_block			*find_lowest(t_block *stack);
t_block			*find_highest(t_block *stack);
t_block			*get_last_block(t_block *lst);
t_block			*create_stack(int ac, char **argv);
t_block			*find_cheapest(t_block *stack_a, t_block *stack_b);
t_block			*next_lowest(t_block *stack_b, t_block *cheapest);
t_block			*next_highest(t_block *stack_a, t_block *match);
void			add_block_at_back(t_block **lst, t_block *new_block);
void			ft_putchar_ptr(int c);
void			ft_putstr(char *str);
void			ft_putptr_hex(unsigned long l_ptr, char *base);
void			ft_putstr_fd(char *str, int fd);	
void			ft_putendl_fd(char *s, int fd);
void			ft_print_stack(t_block **stack);
void			algo_of_3(t_block **stack_a);
void			al_go_5(t_block **s_a, t_block **s_b, int size, int pos_low);
void			algo_of_5(t_block **stack_a, t_block **stack_b);
void			push_back_to_a(t_block **stack_, t_block **stack_b);
void			big_sort(t_block **stack_a, t_block **stack_b);
void			big_sort_ending(t_block **stack_a, t_block **stack_b);
void			move_to_top_b(t_block **stack_b, t_block *match);
void			move_to_top_a(t_block **stack_a, t_block *cheapest);
void			swap_and_rotate(t_block **stack);
void			swap_and_reverse_rotate(t_block **stack);
void			push_to_b_normal(t_block **stack_a, t_block **stack_b, \
				t_block *cheapest, t_block *match);
void			push_to_b_rr(t_block **stack_a, t_block **stack_b, \
				t_block *cheapest, t_block *match);
void			push_to_b_rrr(t_block **stack_a, t_block **stack_b, \
				t_block *cheapest, t_block *match);
void			push_swap(t_block **stack_a, t_block **stack_b, int size_chain);
void			free_stack(t_block **stack);

#endif
