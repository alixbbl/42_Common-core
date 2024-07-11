# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:34:18 by alibourb          #+#    #+#              #
#    Updated: 2023/06/14 15:34:18 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philosophers

SRC 			= \
					utils_parsing.c utils.c \
					check_args.c initialization.c \
					actions.c monitoring.c \
					routine.c main.c \

OBJ = $(SRC:.c=.o)

CC				= gcc
# CC				= gcc -fsanitize=thread
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

all:			$(NAME)

$(NAME): $(OBJ)
				$(CC) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
