/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:03:33 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 18:37:10 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*get_game_data(char *filename)
{
	t_game	*data;

	data = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!data)
		return (NULL);
	data->map_data = is_it_valid_map(filename, data);
	if (!data->map_data)
		return (free(data), NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_copy(data->map_data, data->map_height - 1),
			free_mlx_ptr(data), NULL);
	if ((get_img_ptr(data) < 0))
		return (free_copy(data->map_data, data->map_height - 1),
			free_mlx_ptr(data), NULL);
	data->mlx_win = mlx_new_window(data->mlx, data->map_width * 32,
			data->map_height * 32, "so_long");
	if (!data->mlx_win)
		return (free_copy(data->map_data, data->map_height - 1),
			free_mlx_ptr(data), NULL);
	where_is_player(data->map_data, data);
	return (data);
}

char	**is_it_valid_map(char *filename, t_game *data)
{
	t_list	*map_list;
	t_list	*temp;
	char	**table;

	map_list = make_map_list(filename);
	if (!map_list)
		return (ft_printf("Error\n"), NULL);
	temp = map_list;
	if (map_check(temp) < 0 || goal_check(temp))
	{
		ft_printf("Error: Invalid Map\n");
		free_list(&map_list);
		return (NULL);
	}
	table = make_copy(temp);
	if (!table)
		return (ft_printf("Error\n"), free_list(&map_list), NULL);
	data->map_width = where_is_nl(map_list->str);
	data->map_height = count_list(map_list);
	if (data->map_width > 60 || data->map_height > 31)
		return (ft_printf("Error: Too Big Map(max. 31 * 61)\n"),
			free_list(&map_list), NULL);
	free_list(&map_list);
	return (table);
}

void	where_is_player(char **table, t_game *data)
{
	int	i;
	int	j;
	int	find;

	find = 0;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (table[i][j])
		{
			if (table[i][j] == 'P')
			{
				find++;
				break ;
			}
			j++;
		}
		if (find > 0)
			break ;
		i++;
	}
	data->player_x = i;
	data->player_y = j;
}

void	free_mlx_ptr(t_game *data)
{
	void	*img_ptr[6];
	int		i;

	img_ptr[0] = data->wall.ptr;
	img_ptr[1] = data->player.ptr;
	img_ptr[2] = data->field.ptr;
	img_ptr[3] = data->money.ptr;
	img_ptr[4] = data->exit.ptr;
	img_ptr[5] = data->clear.ptr;
	i = 0;
	while (i < 6)
	{
		if (img_ptr[i])
			mlx_destroy_image(data->mlx, img_ptr[i]);
		i++;
	}
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int	get_img_ptr(t_game *data)
{
	data->wall.ptr = mlx_xpm_file_to_image(data->mlx, "./image/wall.xpm",
			&data->wall.width, &data->wall.height);
	if (!data->wall.ptr)
		return (-1);
	data->field.ptr = mlx_xpm_file_to_image(data->mlx, "./image/field.xpm",
			&data->field.width, &data->field.height);
	if (!data->field.ptr)
		return (-1);
	data->player.ptr = mlx_xpm_file_to_image(data->mlx, "./image/player.xpm",
			&data->player.width, &data->player.height);
	if (!data->player.ptr)
		return (-1);
	data->money.ptr = mlx_xpm_file_to_image(data->mlx, "./image/money.xpm",
			&data->money.width, &data->money.height);
	if (!data->money.ptr)
		return (-1);
	data->exit.ptr = mlx_xpm_file_to_image(data->mlx, "./image/exit.xpm",
			&data->exit.width, &data->exit.height);
	if (!data->exit.ptr)
		return (-1);
	data->clear.ptr = mlx_xpm_file_to_image(data->mlx, "./image/clear.xpm",
			&data->clear.width, &data->clear.height);
	if (!data->clear.ptr)
		return (-1);
	return (0);
}
