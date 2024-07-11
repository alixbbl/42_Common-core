# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 11:14:52 by alibourb          #+#    #+#              #
#    Updated: 2023/04/07 11:14:52 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	pipex

SRC =	pipex.c paths_and_commands.c pipex_utils.c \
		ft_split.c \

OBJ = 		$(SRC:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME): 	$(OBJ)
				$(CC) $(OBJ) $(CCFLAGS) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
