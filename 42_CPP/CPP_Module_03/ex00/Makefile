# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:28:57 by alibourb          #+#    #+#              #
#    Updated: 2023/12/22 15:33:11 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= claptrap

SRC 			= \
					main.cpp \
					ClapTrap.cpp \

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
