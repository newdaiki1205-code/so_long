/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:40:43 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 17:55:49 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *read_str, int fd, t_list *head)
{
	free(read_str);
	while (1)
	{
		read_str = get_next_line(fd);
		if (!read_str)
			break ;
		free(read_str);
	}
	close(fd);
	free_list(&head);
}

int	nl_finder(char *str)
{
	int	i;
	int	nl;

	i = 0;
	nl = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nl++;
		i++;
	}
	if (nl < 1)
		return (1);
	return (0);
}

int	where_is_nl(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	is_it_closed(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			return (-1);
		i++;
	}
	return (i);
}

int	count_char(t_list *current, t_mapcheck *data_box, int i)
{
	if (current->str[i] == 'P')
		data_box->p++;
	else if (current->str[i] == 'E')
		data_box->e++;
	else if (current->str[i] == 'C')
		data_box->c++;
	else if (current->str[i] != '0' && current->str[i] != '1'
		&& current->str[i] != '\n')
		return (-1);
	return (0);
}
