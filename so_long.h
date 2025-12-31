#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list 
{
    char *str;
    int line;
    struct s_list *next;
}               t_list;

typedef struct s_mapcheck
{
    int p;
    int e;
    int c;
}           t_mapcheck;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int check_lines(char *file_name);
char **make_map_data(char *file_name);
int count_list(t_list *head);
int map_check(t_list *head);
int check_char(t_list *current, t_mapcheck *data_box, int size);
int check_wall(char *str, int line, int size);
t_mapcheck *make_data_box(void);

#endif