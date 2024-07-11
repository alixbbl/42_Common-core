# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 14:04:42 by alibourb          #+#    #+#              #
#    Updated: 2023/10/06 14:42:37 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= MyPhoneBook

SRC 			= \
					PhoneBook.cpp \
					Contact.cpp \
					main.cpp \

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
