/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:57:44 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/04 22:01:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void window_manager(t_game *data)
{	
	render_window(data);
    mlx_key_hook(data->mlx_win, handle_input, data);
    mlx_loop(data->mlx);
}

void	render_window(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map_data[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall.ptr, x * data->wall.width, y
					* data->wall.height);
			else if (data->map_data[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->field.ptr, x * data->field.width, y
					* data->field.height);
			else if (data->map_data[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->player.ptr, x * data->player.width, y
					* data->player.height);
			else if (data->map_data[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->money.ptr, x * data->money.width, y
					* data->money.height);
			else if (data->map_data[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->exit.ptr, x * data->exit.width, y
					* data->exit.height);
			else
				break ;
			x++;
		}
		y++;
	}
}

int	handle_input(int keycode, t_game *data)
{
	int	x;
	int	y;

	if (keycode == 65307)
	{
		free_copy(data->map_data, data->map_height - 1);
		free_mlx_ptr(data);
		exit(0);
	}
	x = data->player_x;
	y = data->player_y;
	if (keycode == 119) // W
		redraw_map(x - 1, y, data);
	if (keycode == 97) // A
		redraw_map(x, y - 1, data);
	if (keycode == 115) // S
		redraw_map(x + 1, y, data);
	if (keycode == 100) // D
		redraw_map(x, y + 1, data);
	return (0);
}

void	redraw_map(int next_x, int next_y, t_game *data)
{
	int	x;
	int	y;

	if (data->map_data[next_x][next_y] == '1')
		return ;
	else if (data->map_data[next_x][next_y] == 'E')
	{
		if (do_you_collect_all(data->map_data, data->map_height) < 0)
			return ;
		you_get_goal(data);
		return ;
	}
	x = data->player_x;
	y = data->player_y;
	data->map_data[x][y] = '0';
	data->map_data[next_x][next_y] = 'P';
	data->player_x = next_x;
	data->player_y = next_y;
	render_window(data);
	data->move_count++;
	ft_printf("Move Count: %d\n", data->move_count);
}

void	you_get_goal(t_game *data)
{
	int	color;
	int win_center_x;
	int win_center_y;

	color = 0x00FFFF00;
	win_center_x = data->map_width * 32 / 2 - 32;
	win_center_y = data->map_height * 32 / 2;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, win_center_x - 32, win_center_y - 32, color, "Mission Completed");
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->clear.ptr, win_center_x, win_center_y);
	mlx_string_put(data->mlx, data->mlx_win, win_center_x, win_center_y + 64, color, "See you");
}

int	do_you_collect_all(char **table, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (table[x][y])
		{
			if (table[x][y] == 'C')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}
