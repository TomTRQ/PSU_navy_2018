/*
** EPITECH PROJECT, 2019
** position_error.c
** File description:
** navy
*/

#include "my.h"

int second_cordinates_error(char **cordinates, int i)
{
    if (my_char_isnum(cordinates[i][3]) == 0 || \
        my_char_isnum(cordinates[i][6]) == 0)
        return (84);
    if (cordinates[i][3] - 48 == 0 || cordinates[i][3] - 48 == 9 || \
        cordinates[i][6] - 48 == 0 || cordinates[i][6] - 48 == 9)
        return (84);
    if (cordinates[i][2] < 65 || cordinates[i][2] > 72 || \
        cordinates[i][5] < 65 || cordinates[i][5] > 72)
        return (84);
    if (cordinates[i][3] - 48 > cordinates[i][6] - 48)
        return (84);
    if (cordinates[i][2] - cordinates[i][5] > 0)
        return (84);
    return (0);
}

int cordinates_error(char **cordinates)
{
    int i = 0;
    int count = 2;

    while (i != 4) {
        if ((cordinates[i][0] - 48) != count)
            return (84);
        if (cordinates[i][1] != ':' || cordinates[i][4] != ':')
            return (84);
        if (my_strlen(cordinates[i]) > 8)
            return (84);
        if (second_cordinates_error(cordinates, i) == 84)
            return (84);
        count = count + 1;
        i = i + 1;
    }
    if (i != 4)
        return (84);
    return (0);
}

int pos_error(int argc, char **argv)
{
    int fd = 0;
    char *buffer = NULL;
    int size = 0;
    char **cordinates = NULL;

    if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else if (argc == 3)
        fd = open(argv[2], O_RDONLY);
    buffer = malloc(sizeof(char) * (size + 45));
    read(fd, buffer, 45);
    close(fd);
    cordinates = buffer_to_tab(buffer);
    if (cordinates_error(cordinates) == 84)
        return (84);
    return (0);
}
