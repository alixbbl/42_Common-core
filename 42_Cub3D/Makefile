NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I./includes
MLX_INCLUDE =
MLX_DIR=./mlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

#source
SRCS_DIR = sources/
SRCS = main.c save_data.c utils.c parsing.c color.c hooks.c ray_cast.c\
		draw.c init.c parsing_utils.c game.c fill_data.c close.c save_map.c\

SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

#objsm
OBJS = $(SRCS_PREFIXED:.c=.o)

all : $(NAME)

%.o: %.c ./includes/cub3d.h
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@
$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -lm $(MLX_FLAGS) -o $(NAME)
	@echo $(NAME) is built

clean :
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJS)
	@echo cleaning

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)
	@rm -rf libmlx.dylib
	@echo "full clean"

re : fclean all

.PHONY	: all clean fclean re help
