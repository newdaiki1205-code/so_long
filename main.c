/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:56:10 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 22:34:03 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char *file_name;
	t_game *game_data;

	if (ac != 2)
		return (1);
	file_name = av[1];
	game_data = get_game_data(file_name);
	if (!game_data)
		return (1);
	render_window(game_data);
    mlx_key_hook(game_data->mlx_win, handle_input, game_data);
    mlx_loop(game_data->mlx);
	return (0);
}