/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:56:57 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/04 21:11:42 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	int				line;
	struct s_list	*next;
}					t_list;

typedef struct s_mapcheck
{
	int				p;
	int				e;
	int				c;
}					t_mapcheck;

typedef struct s_goalcheck
{
	int				x;
	int				y;
}					t_goalcheck;

typedef struct s_img
{
	void			*ptr;
	int				width;
	int				height;
}					t_img;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	t_img			wall;
	t_img			field;
	t_img			exit;
	t_img			player;
	t_img			money;
	t_img			clear;
	char			**map_data;
	int				map_width;
	int				map_height;
	int				player_x;
	int				player_y;
	int				move_count;
}					t_game;

int					ft_strlen(const char *s);
char				*ft_strdup(const char *s);
int					check_lines(char *file_name);
char				**make_map_data(char *file_name);
int					count_list(t_list *head);
int					map_check(t_list *head);
int					check_char(t_list *current, t_mapcheck *data_box, int size);
int					check_wall(char *str, int line, int size);
t_mapcheck			*make_data_box(void);
int					goal_check(t_list *map_data);
char				**make_copy(t_list *map_data);
void				free_copy(char **copy, int i);
t_goalcheck			*before_check(char **table, int size, int flag);
void				find_player(t_goalcheck *result, char **table);
void				flood_fill(char **table, t_goalcheck *size,
						t_goalcheck *begin);
void				fill(char **table, t_goalcheck *size, char wall, int row,
						int col);
int					final_check(char **table, int size);
int					is_it_same(t_list *head);
int					nl_finder(char *str);
int					where_is_nl(char *str);
int					is_it_closed(char *str);
t_game				*get_game_data(char *filename);
char				**is_it_valid_map(char *filename, t_game *data);
void				render_window(t_game *data);
void				free_list(t_list **head);
t_list				*make_map_list(char *file_name);
int					handle_input(int keycode, t_game *data);
void				where_is_player(char **table, t_game *data);
void				redraw_map(int next_x, int next_y, t_game *data);
void				you_get_goal(t_game *data);
int					do_you_collect_all(char **table, int size);
void				free_mlx_ptr(t_game *data);
void				window_manager(t_game *data);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					get_img_ptr(t_game *data);

#endif