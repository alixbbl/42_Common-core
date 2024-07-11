# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 14:28:07 by alibourb          #+#    #+#              #
#    Updated: 2023/12/14 14:19:28 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= violenceinutile

SRC 			= \
					main.cpp \
					Weapon.cpp \
					HumanA.cpp \
					HumanB.cpp \

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
