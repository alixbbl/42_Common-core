

NAME 			= HarlFilter

SRC 			= \
					main.cpp \
					Harl.cpp \

OBJ = $(SRC:.cpp=.o)

CC				= c++
RM				= rm -f
CFLAGS	= -Werror -Wextra -Wall -Wimplicit-fallthrough=0 -std=c++98

all:			$(NAME)

$(NAME): $(OBJ)
				$(CC) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
