/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:04:13 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/02 23:12:44 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

void	free_free(int re, char **s);
char	*ft_strjoin_result(char *s1, char *s2);
char	*make_result(char **save, char *buf, int re);
int		eof_checker(char **buf, char **save);
int		make_buf_and_read(char **buf, int fd);
char	*make_save(char **save, char **buf, int re);
size_t	check(const char *s, int flag);
char	*ft_strjoin_save(char *s1, char *s2);
char	*get_next_line(int fd);

#endif