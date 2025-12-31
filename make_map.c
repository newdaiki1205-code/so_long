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

//#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int check_lines(char *file_name)
{
    int fd;
    char *re_str;
    int count;

    fd = open(file_name, O_RDONLY);
    count = 0;
    while((re_str = get_next_line(fd)))
    {
        count++;
        free(re_str);
    }
    close(fd);
    printf("%d\n", count);
    return count;
}

char **make_map_data(char *file_name)
{
    int size;
    int fd;
    char *read_str;
    int i;
    char **map_data;

    size = 5; //check_lines(file_name);
    map_data = (char **)malloc(sizeof(char*) * (size + 1));
    if(!map_data)
        return NULL;
    i = 0;
    fd = open(file_name, O_RDONLY);
    while((read_str = get_next_line(fd)))
    {
        map_data[i] = ft_strdup(read_str);
        i++;
        free(read_str);
    }
    map_data[i] = NULL;
    close(fd);
    return map_data;
}

int main(int ac, char **av)
{
    char    *file_name;
    char    **map_data;
    int i = 0;

    if(ac != 2)
        return 1;
    file_name = av[1];
    map_data = make_map_data(file_name);
    printf("\n");

    int j = 0;
    while (map_data[j])
        j++;
    printf("\nTotal lines in map_data: %d\n", j);
    while(map_data[i])
    {
        printf("%s", map_data[i]);
        i++;
    }
    // i = 0;
    // while(map_data[i])
    // {
    //     free(map_data[i]);
    //     i++;
    // }
    // free(map_data);
 	return (0);
}