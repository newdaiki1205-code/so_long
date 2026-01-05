/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:25:15 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 17:55:56 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*make_newnode(char *str)
{
	t_list	*new;

	if (!str)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str);
	if (!(new->str))
		return (free(new), NULL);
	new->next = NULL;
	return (new);
}

void	add_last(t_list **head, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	free_list(t_list **head)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *head;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev->str);
		free(prev);
	}
	*head = NULL;
}

int	count_list(t_list *head)
{
	t_list	*current;
	int		i;

	if (!head)
		return (0);
	current = head;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_list	*make_map_list(char *file_name)
{
	t_list	*head;
	t_list	*new;
	int		fd;
	char	*read_str;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	head = NULL;
	i = 0;
	while (1)
	{
		read_str = get_next_line(fd);
		if (!read_str)
			break ;
		new = make_newnode(read_str);
		if (!new)
			return (error_map(read_str, fd, head), (NULL));
		new->line = i;
		add_last(&head, new);
		i++;
		free(read_str);
	}
	return (close(fd), head);
}
