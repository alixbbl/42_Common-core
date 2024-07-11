# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 11:46:43 by alibourb          #+#    #+#              #
#    Updated: 2022/11/16 14:08:20 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
#libft.a est le nom du programme, on le met dans une variable NAME ecrite $(NAME)
#on cree la var SRC qui regroupe les diff fichiers des fonctions(codes sources)

SRC	= \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	ft_toupper.c

BONUS_SRC = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)
CC			= gcc 
CCFLAGS  	= -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAME)
#NAME est le nom de l'executable(impose par la consigne 42)

$(NAME):	$(OBJ)
				ar -rcs $(NAME) $(OBJ)

bonus :		$(OBJ) $(BONUS_OBJ)
				ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:		
				$(RM) $(OBJ) $(BONUS_OBJ)
#nettoie, on suppr les codes obj crees.

fclean:		clean
				$(RM) $(NAME)
#supprime tout, clean est lancee en meme temps.
re:				fclean all

.PHONY:		 all bonus clean fclean re
#ajout des commandes liees aux bonus cas echeant