NAME = so_long

SRC = main.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./printf/ft_printf.c \
		./printf/ft_putstr_fd.c \
		./printf/ft_specifier.c \
		./printf/print.c \
		./printf/ft_putnbr_base.c \
		./map_handling/map_list.c \
		./map_handling/map_check.c \
		./map_handling/so_long_helper.c \
		./map_handling/goal_check.c \
		./map_handling/flood_fill.c \
		./graphic_manage/mlx_data.c \
		./graphic_manage/window_handling.c \


CC = cc
FLAGS = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
STD_LIB = -L/usr/lib -lXext -lX11 -lm -lz

MLX_HEAD = -I$(MLX_DIR)
STD_HEAD = -I/usr/include
GNL_HEAD = -I./get_next_line
PRTF_HEAD = -I./printf
MY_HEAD = -I.


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(STD_LIB) $(MLX_HEAD) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) $(STD_HEAD) $(MLX_HEAD) $(GNL_HEAD) $(PRTF_HEAD) $(MY_HEAD) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
