/*
** EPITECH PROJECT, 2019
** handling_maps.c
** File description:
** Navy
*/

#include "my.h"

int win_lose_check(char **map, int epid)
{
    int lin = 3;
    int col = 2;

    while (map[lin] != NULL) {
        if (map[lin][col] != '.' && map[lin][col] != ' ' && \
            map[lin][col] != 'o' && map[lin][col] != 'x' && \
            map[lin][col] != '\n' && map[lin][col] != '\0') {
                kill(epid, SIGUSR2);
                usleep(200);
                return (0);
            }
        if (col == 16) {
            col = 2;
            lin = lin + 1;
        }
        col = col + 1;
    }
    kill(epid, SIGUSR1);
    usleep(200);
    return (1);
}

char **create_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++) {
        map[i] = malloc(sizeof(char) * 21);
        if (map == NULL || map[i] == NULL)
            return (NULL);
    }
    my_strcpy(map[0], "my positions:\n\0");
    my_strcpy(map[1], " |A B C D E F G H\n\0");
    my_strcpy(map[2], "-+---------------\n\0");
    my_strcpy(map[3], "1|. . . . . . . .\n\0");
    my_strcpy(map[4], "2|. . . . . . . .\n\0");
    my_strcpy(map[5], "3|. . . . . . . .\n\0");
    my_strcpy(map[6], "4|. . . . . . . .\n\0");
    my_strcpy(map[7], "5|. . . . . . . .\n\0");
    my_strcpy(map[8], "6|. . . . . . . .\n\0");
    my_strcpy(map[9], "7|. . . . . . . .\n\0");
    my_strcpy(map[10], "8|. . . . . . . .\n\0");
    map[11] = NULL;
    return (map);
}

char **buffer_to_tab(char *buffer)
{
    char **cordinates = malloc(sizeof(char *) * 11);
    int i = 0;
    int x = 0;
    int y = 0;

    cordinates[y] = malloc(sizeof(char) * 9);
    while (buffer[i] != '\0') {
        if (cordinates == NULL || cordinates[y] == NULL)
            return (NULL);
        cordinates[y][x] = buffer[i];
        x++;
        if (buffer[i] == '\n') {
            x = 0;
            y++;
            cordinates[y] = malloc(sizeof(char) * 9);
        }
        i++;
    }
    return (cordinates);
}

char **players_map(char *str)
{
    int fd = open(str, O_RDONLY);
    char *buffer = NULL;
    char **map = NULL;

    buffer = malloc(sizeof(char) * 45);
    read(fd, buffer, 45);
    close(fd);
    map = add_cordinates_to_map(buffer, map);
    return (map);
}

char ***creating_gameboard(int player, char **argv)
{
    char ***board = malloc(sizeof(char **) * 3);

    if (board == NULL)
        return (NULL);
    if (player == 0)
        board[0] = players_map(argv[1]);
    if (player == 1)
        board[0] = players_map(argv[2]);
    board[1] = create_empty_map();
    board[2] = NULL;
    return (board);
}
