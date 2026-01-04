/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:56:10 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/04 19:29:56 by dshirais         ###   ########.fr       */
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
	window_manager(game_data);
	return (0);
}