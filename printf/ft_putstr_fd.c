/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:50:00 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/04 18:47:46 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
// int main()
// {
//     // int fd;
//     // char *s = "Hello, World!";

//     // fd = open("string.txt", O_RDWR | O_CREAT, 0700);
//     // if(fd == -1)
//     //     return (1);
//     // ft_putstr_fd(s, fd);
//     // close(fd);
// 	ft_putstr_fd(NULL, 1);
//     return (0);
// }