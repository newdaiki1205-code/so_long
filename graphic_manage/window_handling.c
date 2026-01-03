/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:57:44 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 22:48:48 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_window(t_game *data)
{
	size_t	x;
	int		y;

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

int handle_input(int keycode, t_game *data) 
{
    int x;
    int y;

    if (keycode == 65307) 
        exit(0);
    x = data->player_x;
    y = data->player_y;
    if(keycode == 119)//W
        redraw_map(x-1, y, data);
    if(keycode == 97)//A
        redraw_map(x, y-1, data);
    if(keycode == 115)//S
        redraw_map(x+1, y, data);
    if(keycode == 100)//D
        redraw_map(x, y+1, data);
    return (0);
}

void redraw_map(int next_x, int next_y, t_game *data)
{
    int x;
    int y;

    if(data->map_data[next_x][next_y] == '1')
        return ;
    x = data->player_x;
    y = data->player_y;
    data->map_data[x][y] = '0';
    data->map_data[next_x][next_y] = 'P';
    data->player_x = next_x;
    data->player_y = next_y;
    render_window(data);
}
