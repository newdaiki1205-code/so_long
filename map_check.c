#include "so_long.h"
#include <stdio.h>

int map_check(t_list *head)
{
    t_list *current;
    t_mapcheck *data_box;
    int size;

    current = head;
    size = count_list(current);
    if(size < 0 || size < 3)
        return -1;
    data_box = make_data_box();
    check_char(current, data_box, size);
    return free(data_box), 0;
}

t_mapcheck *make_data_box(void)
{
    t_mapcheck *data_box;

    data_box = (t_mapcheck*)malloc(sizeof(t_mapcheck));
    if(!data_box)
        return NULL;
    data_box->c = 0;
    data_box->e = 0;
    data_box->p = 0;
    return data_box;
}

int check_char(t_list *current, t_mapcheck *data_box, int size)
{
    size_t i;
    
    i = 0;
    while(current)
    {
        i = 0;
        printf("loop %d\n", current->line);
        while(i < ft_strlen(current->str))
        {
            if((check_wall(current->str, current->line, size) < 0))
                return -1;
            if(current->str[i] == 'P')
                data_box->p++;
            else if(current->str[i] == 'E')
                data_box->e++;
            else if (current->str[i] == 'C')
                data_box->c++;
            else if (current->str[i] != '0' && current->str[i] != '1')
                return -1;
            i++;
        }
        current = current->next;
    }
    printf("p:%d e:%d c:%d", data_box->p, data_box->e, data_box->c);
    if(data_box->p != 1 || data_box->e != 1 || data_box->c < 1)
        return -1;
    return 0;
}

int check_wall(char *str, int line, int size)
{
    int i;

    i = 0;
    if((line != 0 && line != size -1) && (str[0] != '1' || str[ft_strlen(str) - 1] != '1'))
        return -1;
    else if (line != 0 && line != size -1)
        return 0;
    while(str[i])
    {
        if(str[i] != '1' && str[i] != '\n')
            return -1;
        i++;
    }
    return 0;
}