/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:30:02 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/29 17:15:20 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_result(char **save, char *buf, int re);
int		make_buf_and_read(char **buf, int fd);
char	*make_save(char **save, char **buf, int re);
char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*result;
	char		*buf;
	int			re;

	while (1)
	{
		re = make_buf_and_read(&buf, fd);
		if (re < 0)
			return (free_free(re, &save), NULL);
		if (re == 0 || check(buf, 1))
			break ;
		if (save && check(save, 1))
			break ;
		else
			save = make_save(&save, &buf, re);
	}
	if (re == 0 && eof_checker(&buf, &save))
		return (NULL);
	result = make_result(&save, buf, re);
	if (!result)
		return (free_free(re, &buf), free_free(re, &save), NULL);
	if (save || buf || re != 0)
		save = make_save(&save, &buf, re);
	return (free_free(re, &buf), result);
}

int	make_buf_and_read(char **buf, int fd)
{
	int	re;

	*buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!(*buf))
		return (-1);
	re = read(fd, *buf, BUFFER_SIZE);
	if (re < 0)
	{
		free(*buf);
		buf = NULL;
		return (re);
	}
	(*buf)[re] = '\0';
	return (re);
}

char	*make_result(char **save, char *buf, int re)
{
	char	*new;

	if (re == 0)
		new = ft_strjoin_result(*save, NULL);
	else if (!save || !*save)
		new = ft_strjoin_result(buf, NULL);
	else if (check(*save, 1))
		new = ft_strjoin_result(*save, NULL);
	else
		new = ft_strjoin_result(*save, buf);
	if (!new)
		return (NULL);
	if (*save && !check(*save, 1))
		free_free(re, save);
	if (re == 0 && *save && !(check(*save, 1)))
		free_free(re, save);
	return (new);
}

char	*make_save(char **save, char **buf, int re)
{
	char	*new;

	if (re == 0 && *save)
		new = ft_strjoin_save(&(*save)[check(*save, 1)], NULL);
	else if (!(*save))
		new = ft_strjoin_save(&(*buf)[check(*buf, 1)], NULL);
	else if (check(*save, 1))
		new = ft_strjoin_save(&(*save)[check(*save, 1)], *buf);
	else
		new = ft_strjoin_save(*save, *buf);
	if (!new)
		return (free_free(re, buf), free_free(re, save), NULL);
	if (*save)
		free_free(re, save);
	if (*buf)
		free_free(re, buf);
	return (new);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*test;

//  	fd = open("map.ber", O_RDONLY);
//  	while ((test = get_next_line(fd)))
//  	{
//  		printf("line %s", test);
//  		free(test);
//  	}
//  	close(fd);
//  	return (0);
// }
