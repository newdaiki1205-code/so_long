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
    if(!data_box)
        return -1;
    if (check_char(current, data_box, size) < 0)
		return (-1);
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
	size_t	i;

	i = 0;
	while (current)
	{
		if ((check_wall(current->str, current->line, size) < 0))
			return (-1);
		i = 0;
		while (i < ft_strlen(current->str))
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
    size_t len;

	len = where_is_nl(str);
	if(len < 1)
		return (-1);
	if(str[0] != '1' || str[len - 1] != '1')
		return (-1);
	if((line == 0 || line == size - 1) && (is_it_closed(str) < 0))
		return (-1);
	return 0;
}

int	is_it_same(t_list *head)
{
	t_list	*current;
	int		i;
	size_t	len;
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

size_t  where_is_nl(char *str)
{
    size_t  i;

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
    return i;
}
