#include "so_long.h"
#include <stdio.h>
// #include "map_check.c"
// #include "so_long_helper.c"
// #include "get_next_line.c"
// #include "get_next_line_utils.c"

t_list *make_newnode(char *str)
{
    t_list *new;

    new = (t_list*)malloc(sizeof(t_list));
    if(!new)
        return NULL;
    new->str = str;
    new->next = NULL;
    return new;
}

void add_last(t_list **head, t_list *new)
{
    t_list *current;
    
    if(!head || !new)
        return ;
    if(!(*head))
    {
        *head = new;
        return ;
    }
    current = *head;
    while(current->next)
        current = current->next;
    current->next = new;
}

void free_list(t_list **head)
{
    t_list *prev;
    t_list *current;

    prev = NULL;
    current = *head;
    while(current->next)
    {
        prev = current;
        current = current->next;
        free(prev->str);
        free(prev);
    }
    free(current);
}

int count_list(t_list *head)
{
    t_list *current;
    int i;
    size_t len;

    if(!head)
        return 0;
    current = head;
    i = 0;
    len = ft_strlen(current->str);
    while(current)
    {
        if(len != ft_strlen(current->str))
            return -1;
        i++;
        current = current->next;
    }
    return i;
}

t_list *make_map_list(char *file_name)
{
    t_list *head;
    t_list *new;
    int fd;
    char *read_str;
    char *dup_str;
    int i;

    fd = open(file_name, O_RDONLY);
    if(!fd)
        return NULL;
    head = NULL;
    i = 0;
    while((read_str = get_next_line(fd)))
    {
        dup_str = ft_strdup(read_str);
        new = make_newnode(dup_str);
        if(!new)
            return free_list(&head), NULL;
        new->line = i;
        add_last(&head, new);
        i++;
        free(read_str);
    }
    close(fd);
    return head;
}

int main(int ac, char **av)
{
    char    *file_name;
    t_list   *map_data;
    t_list *temp;

    if(ac != 2)
        return 1;
    file_name = av[1];
    map_data = make_map_list(file_name);
    if(!map_data)
        return 1;
    temp = map_data;
    if(map_check(temp) < 0 || goal_check(temp))
        printf("Error: Invalid Map");
    // printf("%d\n", count_list(temp));
    // while(temp)
    // {
    //     printf("%s", temp->str);
    //     temp = temp->next;
    // }
    free_list(&map_data);
 	return (0);
}