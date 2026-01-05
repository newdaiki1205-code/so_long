/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:50:47 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 14:53:18 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **table, t_goalcheck *size, t_goalcheck *begin)
{
	fill(table, size, begin->y, begin->x);
}

void	fill(char **table, t_goalcheck *size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size->y || col >= size->x)
		return ;
	if (table[col][row] == 'F' || table[col][row] == '1')
		return ;
	table[col][row] = 'F';
	fill(table, size, row + 1, col);
	fill(table, size, row - 1, col);
	fill(table, size, row, col + 1);
	fill(table, size, row, col - 1);
}

int	final_check(char **table, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (table[x][y])
		{
			if (table[x][y] == 'E' || table[x][y] == 'C')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}
