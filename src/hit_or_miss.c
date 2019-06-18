/*
** EPITECH PROJECT, 2019
** hit_or_miss.c
** File description:
** navy
*/

#include "my.h"

char *while_wrong_argument(char *buffer, int end_file)
{
    buffer = get_next_line(0, &end_file);
    if (check_buffer(buffer) == 84) {
        if (end_file == -1)
            return (NULL);
        my_printf("wrong position\n");
        my_printf("attack: ");
        buffer = while_wrong_argument(buffer, end_file);
    }
    return (buffer);
}

char **add_hit_miss_map(char **map, char letter, char number, char hit)
{
    int col = 0;
    int lin = 0;

    while (map[1][col] != letter)
        col = col + 1;
    while (map[lin][0] != number)
        lin = lin + 1;
    map[lin][col] = hit;
    return (map);
}

void send_cords(int epid, char *buffer)
{
    for (int i = 0; i < (buffer[0] - 64); i++) {
        kill(epid, SIGUSR1);
        usleep(150);
    }
    kill(epid, SIGUSR2);
    usleep(200);
    for (int j = 0; j < buffer[1] - 48; j++) {
        kill(epid, SIGUSR1);
        usleep(150);
    }
    kill(epid, SIGUSR2);
    usleep(200);
}

char *receive_cords(char *cords)
{
    struct sigaction rec;
    struct sigaction rec2;
    int i = 0;
    int j = 0;

    write(1, "waiting for enemy's attack...\n", 32);
    set_recs(rec, rec2);
    mod_k(9);
    for (int k = 0; k == 0; i++) {
        pause();
        k = mod_k(0);
    }
    mod_k(9);
    for (int k = 0; k == 0; j++) {
        pause();
        k = mod_k(0);
    }
    cords = trans_cords(cords, i - 1, j - 1);
    return (cords);
}

char *trans_cords(char *cords, int i, int j)
{
    cords[0] = i + 64;
    cords[1] = j + 48;
    cords[2] = '\0';
    return (cords);
}