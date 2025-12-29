/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:19:29 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/29 17:24:24 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int check_lines(int fd)
{
    char *re_str;
    int count;

    count = 0;
    while((re_str = get_next_line(fd)))
    {
        count++;
        free(re_str);
    }
    return count;
}

char **make_map_data(char *file_name)
{
    int fd;
    char *re_str;
    int count;

    fd = open(file_name, O_RDONLY);
    count = check_lines(fd);
    
    close(fd);
    return count;
}


char **put_data(char **map_data)
{
    char *read_str;

    while((read_str = get_next_line)
}

int main(int ac, char **av)
{
    char    *file_name = av[1];
    char    **map_data;
    int count;

    if(ac != 2)
        return 1;

    count = check_lines(file_name);
    map_data = (char **)malloc(sizeof(char*) * (count + 1));
    printf("%d", count);    
 	return (0);
}