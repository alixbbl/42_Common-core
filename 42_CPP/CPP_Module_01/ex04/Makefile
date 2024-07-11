# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 14:18:51 by alibourb          #+#    #+#              #
#    Updated: 2023/12/14 14:19:38 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= sed

SRC 			= \
					main.cpp \
					micro_parsing.cpp \

OBJ = $(SRC:.cpp=.o)

CC				= c++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror --std=c++98

all:			$(NAME)

$(NAME): $(OBJ)
				$(CC) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
