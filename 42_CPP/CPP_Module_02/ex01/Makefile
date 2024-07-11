# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 15:27:40 by alibourb          #+#    #+#              #
#    Updated: 2023/12/14 15:24:08 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= Fixed01

SRC 			= \
					main.cpp \
					Fixed.cpp \

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
