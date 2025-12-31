NAME = so_long

SRC = map_list.c get_next_line.c get_next_line_utils.c map_check.c so_long_helper.c goal_check.c flood_fill.c

CC = cc
FLAGS = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
STD_LIB = -L/usr/lib -lXext -lX11 -lm -lz

MLX_HEAD = -I$(MLX_DIR)
STD_HEAD = -I/usr/include
MY_HEAD = -I.


all: $(NAME)

$(NAME): $(OBJ)
#	$(CC) $(OBJ) $(MLX_LIB) $(STD_LIB) $(MLX_HEAD) -o $(NAME)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.c
#	$(CC) $(FLAGS) $(STD_HEAD) $(MLX_HEAD) $(MY_HEAD) -O3 -c $< -o $@
	$(CC) $(FLAGS) $(STD_HEAD) $(MY_HEAD) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
