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

NAME						= libftprintf.a

SRC							= \
											ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr_uns.c \
											ft_putnbr.c ft_putptr.c ft_putnbr_hex.c

OBJ							= $(SRC:.c=.o)

CC								= gcc 
CCFLAGS  	= -Wall -Wextra -Werror
RM								= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
				ar -rcs $(NAME) $(OBJ)

clean:		
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		 all clean fclean re