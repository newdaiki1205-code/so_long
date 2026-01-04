/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:34:49 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/04 18:47:46 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check(const char *s, int flag)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && flag > 0)
			return (i + 1);
		i++;
	}
	if (flag > 0)
		return (0);
	return (i);
}

int	eof_checker(char **buf, char **save)
{
	if (!*(save))
	{
		free(*buf);
		return (1);
	}
	if ((*save)[0] == '\0')
	{
		free(*buf);
		free(*save);
		return (1);
	}
	return (0);
}

void	free_free(int re, char **s)
{
	if (!s || !*s)
		return ;
	if (re < 0)
	{
		if (*s)
			free(*s);
		return ;
	}
	free(*s);
	*s = NULL;
}

char	*ft_strjoin_result(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		size;

	if(!s1)
		return NULL;
	if (!s1 && !s2)
		return (NULL);
	if (check(s1, 1) && !s2)
		size = check(s1, 1);
	else if (!check(s1, 1) && !s2)
		size = check(s1, 0);
	else
		size = check(s1, 0) + check(s2, 1);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 && i < size)
		str[i++] = *s1++;
	while (s2 && *s2 && i < size)
		str[i++] = *s2++;
	str[size] = '\0';
	return (str);
}

char	*ft_strjoin_save(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		size;

	if(!s1)
		return NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		size = check(s1, 0);
	else
		size = check(s1, 0) + check(s2, 0);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 && i < size)
		str[i++] = *s1++;
	while (s2 && *s2 && i < size)
		str[i++] = *s2++;
	str[size] = '\0';
	return (str);
}

