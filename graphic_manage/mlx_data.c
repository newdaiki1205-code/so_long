/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:03:33 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 23:19:18 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_game	*get_game_data(char *filename)
{
	t_game	*data;
	size_t	win_width;
	int		win_height;

	data = (t_game *)malloc(sizeof(t_game));
	if (!data)
		return (NULL);
	data->map_data = is_it_valid_map(filename, data);
    if(!data->map_data)
        return free(data), NULL;
    data->mlx = mlx_init();
	data->wall.ptr = mlx_xpm_file_to_image(data->mlx, "./image/wall.xpm",
			&data->wall.width, &data->wall.height);
	data->field.ptr = mlx_xpm_file_to_image(data->mlx, "./image/field.xpm",
			&data->field.width, &data->field.height);
	data->player.ptr = mlx_xpm_file_to_image(data->mlx, "./image/player.xpm",
			&data->player.width, &data->player.height);
	data->money.ptr = mlx_xpm_file_to_image(data->mlx, "./image/money.xpm",
			&data->money.width, &data->money.height);
	data->exit.ptr = mlx_xpm_file_to_image(data->mlx, "./image/exit.xpm",
			&data->exit.width, &data->exit.height);
	win_width = data->map_width* 32;
	win_height = data->map_height * 32;
	data->mlx_win = mlx_new_window(data->mlx, win_width, win_height, "so_long");
    where_is_player(data->map_data, data);
	return (data);
}

char	**is_it_valid_map(char *filename, t_game *data)
{
	t_list *map_list;
    t_list	*temp;
    char **table;

    map_list = make_map_list(filename);
    if(!map_list)
        return NULL;
    temp = map_list;
    if (map_check(temp) < 0 || goal_check(temp))
	{
		ft_printf("Error: Invalid Map\n");
		return (NULL);
	}
    table = make_copy(temp);
    if(!table)
        return NULL;
    data->map_width = where_is_nl(map_list->str);
	data->map_height = count_list(map_list);
    free_list(&map_list);
	return (table);
}

void where_is_player(char **table, t_game *data)
{
    int i;
    int j;
    int find;

    find = 0;
    i = 0;
    while(i < data->map_height)
    {
        j = 0;
        while(table[i][j])
        {
            if(table[i][j] == 'P')
            {
                find++;
                break;
            }
            j++;
        }
        if(find > 0)
            break;
        i++;
    }
    data->player_x = i;
    data->player_y = j;
}

