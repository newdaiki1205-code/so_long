/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:50:11 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 14:51:02 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	goal_check(t_list *map_data)
{
	char		**copy;
	int			size;
	t_goalcheck	*table_size;
	t_goalcheck	*player;

	copy = make_copy(map_data);
	if (!copy)
		return (-1);
	size = count_list(map_data);
	table_size = before_check(copy, size, 0);
	if (!table_size)
		return (free_copy(copy, size - 1), -1);
	player = before_check(copy, size, 1);
	if (!player)
		return (free(table_size), free_copy(copy, size - 1), -1);
	flood_fill(copy, table_size, player);
	if (final_check(copy, size) < 0)
		return (free(table_size), free(player), free_copy(copy, size - 1), -1);
	return (free(table_size), free(player), free_copy(copy, size - 1), 0);
}

char	**make_copy(t_list *map_data)
{
	int		size;
	char	**copy;
	int		i;

	size = count_list(map_data);
	copy = (char **)malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_strdup(map_data->str);
		if (!copy[i])
			return (free_copy(copy, i - 1), NULL);
		map_data = map_data->next;
		i++;
	}
	copy[size] = NULL;
	i = 0;
	return (copy);
}

void	free_copy(char **copy, int i)
{
	while (i >= 0)
	{
		free(copy[i]);
		i--;
	}
	free(copy);
}

t_goalcheck	*before_check(char **table, int size, int flag)
{
	t_goalcheck	*result;

	result = (t_goalcheck *)malloc(sizeof(t_goalcheck));
	if (!result)
		return (NULL);
	if (flag == 0)
	{
		result->x = size;
		result->y = ft_strlen(table[0]);
	}
	else
		find_player(result, table);
	return (result);
}

void	find_player(t_goalcheck *result, char **table)
{
	int	x;
	int	y;

	x = 0;
	while (1)
	{
		y = 0;
		while (table[x][y])
		{
			if (table[x][y] == 'P')
				break ;
			y++;
		}
		if (table[x][y] && table[x][y] == 'P')
			break ;
		x++;
	}
	result->x = x;
	result->y = y;
}
