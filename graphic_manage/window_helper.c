/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:45:52 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 18:30:19 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	you_get_goal(t_game *data)
{
	int	color;
	int	win_center_x;
	int	win_center_y;

	color = 0x00FFFF00;
	win_center_x = data->map_width * 32 / 2 - 32;
	win_center_y = data->map_height * 32 / 2;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, win_center_x - 32, win_center_y
		- 32, color, "Mission Completed");
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->clear.ptr,
		win_center_x, win_center_y);
	mlx_string_put(data->mlx, data->mlx_win, win_center_x, win_center_y + 64,
		color, "See you");
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

int	close_window(t_game *data)
{
	free_copy(data->map_data, data->map_height - 1);
	free_mlx_ptr(data);
	exit(0);
}
