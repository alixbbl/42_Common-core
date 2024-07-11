# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 14:04:42 by alibourb          #+#    #+#              #
#    Updated: 2023/11/05 12:34:41 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= Account

SRC 			= \
					Account.cpp \
					tests.cpp \

OBJ = $(SRC:.cpp=.o)

CC				= g++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror --std=c++98

all:			$(NAME)

$(NAME): $(OBJ)
				$(CC) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
