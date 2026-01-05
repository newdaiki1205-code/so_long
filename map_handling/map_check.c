/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:39:33 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 14:48:22 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	map_check(t_list *head)
{
	t_list		*current;
	t_mapcheck	*data_box;
	int			size;

	current = head;
	size = is_it_same(current);
	if (size < 0 || size < 3)
		return (-1);
	data_box = make_data_box();
	if (!data_box)
		return (-1);
	if (check_char(current, data_box, size) < 0)
		return (free(data_box), -1);
	free(data_box);
	return (0);
}

t_mapcheck	*make_data_box(void)
{
	t_mapcheck	*data_box;

	data_box = (t_mapcheck *)malloc(sizeof(t_mapcheck));
	if (!data_box)
		return (NULL);
	data_box->c = 0;
	data_box->e = 0;
	data_box->p = 0;
	return (data_box);
}

int	check_char(t_list *current, t_mapcheck *data_box, int size)
{
	int	i;

	i = 0;
	while (current)
	{
		if ((check_wall(current->str, current->line, size) < 0))
			return (-1);
		i = 0;
		while (i < ft_strlen(current->str))
		{
			if (count_char(current, data_box, i) < 0)
				return (-1);
			i++;
		}
		current = current->next;
	}
	if (data_box->p != 1 || data_box->e != 1 || data_box->c < 1)
		return (-1);
	return (0);
}

int	check_wall(char *str, int line, int size)
{
	int	len;

	len = where_is_nl(str);
	if (len < 1)
		return (-1);
	if (str[0] != '1' || str[len - 1] != '1')
		return (-1);
	if ((line == 0 || line == size - 1) && (is_it_closed(str) < 0))
		return (-1);
	return (0);
}

int	is_it_same(t_list *head)
{
	t_list	*current;
	int		i;
	int		len;
	int		last;

	if (!head)
		return (0);
	current = head;
	i = 0;
	len = ft_strlen(current->str);
	last = count_list(head);
	while (current)
	{
		if (i == last - 1 && nl_finder(current->str))
			len--;
		if (len != ft_strlen(current->str))
			return (-1);
		i++;
		current = current->next;
	}
	return (i);
}
