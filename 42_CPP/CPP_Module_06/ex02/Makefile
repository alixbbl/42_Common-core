# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 15:45:40 by alibourb          #+#    #+#              #
#    Updated: 2024/01/06 16:58:48 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= therealtype

SRC 			= \
					Base.cpp \
					main.cpp \

OBJ = $(SRC:.cpp=.o)

CC				= c++
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
