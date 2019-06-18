/*
** EPITECH PROJECT, 2019
** modify_map.c
** File description:
** navy
*/

#include "my.h"

char **fill_line(char **cordinates, char **new_map, int i)
{
    int col = 0;
    int lin = 0;
    int len = (cordinates[i][5] - 65) - (cordinates[i][2] - 65) + 1;
    int a = 0;

    while (new_map[1][col] != cordinates[i][2])
        col = col + 1;
    while (new_map[lin][0] != cordinates[i][3])
        lin = lin + 1;
    while (a != len) {
        new_map[lin][col] = cordinates[i][0];
        col = col + 2;
        a = a + 1;
    }
    return (new_map);
}

char **fill_column(char **cordinates, char **new_map, int i)
{
    int col = 0;
    int lin = 0;
    int count = 0;

    while (new_map[1][col] != cordinates[i][2])
        col = col + 1;
    while (new_map[lin][0] != cordinates[i][3])
        lin = lin + 1;
    while (count != cordinates[i][6] - cordinates[i][3] + 1) {
        new_map[lin][col] = cordinates[i][0];
        lin = lin + 1;
        count = count + 1;
    }
    return (new_map);
}

char **add_cordinates_to_map(char *buffer, char **map)
{
    char **cordinates = buffer_to_tab(buffer);
    char **new_map = create_empty_map();
    int i = 0;

    while (i <= 3) {
        if (cordinates[i][2] == cordinates[i][5])
            new_map = fill_column(cordinates, new_map, i);
        else if (cordinates[i][3] == cordinates[i][6])
            new_map = fill_line(cordinates, new_map, i);
        i = i + 1;
    }
    return (new_map);
}
