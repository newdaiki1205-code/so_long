#include "so_long.h"
#include <stdio.h>

void flood_fill(char **table, t_goalcheck *size, t_goalcheck *begin)
{
    char wall = '1';
    fill(table, size, wall, begin->y, begin->x);
}

void fill(char **table, t_goalcheck *size, char wall, int row, int col)
{
    //int i = 0;
    // while(i < 5)
    // {
    //     printf("%s\n", table[i]);
    //     i++;
    // }
    // printf("\n");
    if(row < 0 || col < 0 || row >= size->y || col >= size->x)
        return;
    if(table[col][row] == 'F' || table[col][row] == wall)
        return;
    table[col][row] = 'F';
    fill(table, size, wall, row + 1, col);
    fill(table, size, wall, row - 1, col);
    fill(table, size, wall, row, col + 1);
    fill(table, size, wall, row, col - 1);
}

int final_check(char **table, int size)
{
    int x;
    int y;

    x = 0;
    while(x < size)
    {
        y = 0;
        while(table[x][y])
        {
            if(table[x][y] == 'E' || table[x][y] == 'C')
                return -1;
            y++;
        }
        x++;
    }
    return 0;
}
