NAME = so_long

SRC = make_map.c get_next_line.c get_next_line_utils.c

CC = cc
FLAGS = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
STD_LIB = -L/usr/lib -lXext -lX11 -lm -lz

MLX_HEAD = -I$(MLX_DIR)
STD_HEAD = -I/usr/include
GNL_HEAD = -I.


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(STD_LIB) $(MLX_HEAD) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) $(STD_HEAD) $(MLX_HEAD) $(GNL_HEAD) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
