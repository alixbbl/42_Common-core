# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 11:46:43 by alibourb          #+#    #+#              #
#    Updated: 2022/11/16 14:08:20 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC			= \
				instruc_push.c instruc_reverse_rotate.c parsing.c \
				instruc_swap.c instruc_rotate.c push_swap_utils_2.c \
				push_swap_utils_1.c ft_printf.c ft_putnbr.c \
				ft_putnbr_hex.c ft_putnbr_uns.c ft_putptr.c push_swap.c \
				small_sort.c big_sort.c positions_and_counts.c main.c \
				push_to.c push_swap_utils_3.c

OBJ			= $(SRC:.c=.o)

CC			= gcc 
CCFLAGS  	= -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
				$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

clean:		
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		 all clean fclean re