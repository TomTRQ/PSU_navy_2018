/*
** EPITECH PROJECT, 2019
** second_player_game.c
** File description:
** navy
*/

#include "my.h"

int check_entry(char *cord, char **map)
{
    int col = 0;
    int lin = 0;

    while (map[1][col] != cord[0])
        col = col + 1;
    while (map[lin][0] != cord[1])
        lin = lin + 1;
    if (map[lin][col] == '.' || map[lin][col] == 'x')
        return (1);
    return (0);
}

char *print_second_player_map(char ***game_board, char *cords, int epid)
{
    static int i = 0;

    cords = malloc(sizeof(char) * 3);
    if (cords == NULL)
        return (NULL);
    if (i > 0) {
        if (game_end(game_board) == 1)
            return (NULL);
    }
    for (int a = 0; a < 12; a++)
        my_printf("%s", game_board[0][a]);
    game_board[1][0] = "\nenemy's positions:\n";
    for (int b = 0; b < 12; b++)
        my_printf("%s", game_board[1][b]);
    my_printf("\n");
    cords = receive_cords(cords);
    print_hit_miss_on_map(game_board, cords, epid);
    i++;
    return (cords);
}

int get_buffer_free(char ***game_board, char *buffer, int end_file, int epid)
{
    my_printf("attack: ");
    buffer = while_wrong_argument(buffer, end_file);
    if (buffer == NULL)
        return (84);
    usleep(100);
    print_check_hit(buffer, epid, game_board);
    free(buffer);
    return (0);
}

int game_second_player(int epid, char ***game_board, int *win)
{
    int end_file = 0;
    int c_hit = 0;
    char *buffer = malloc(sizeof(char) * 3);
    char *cords = print_second_player_map(game_board, cords, epid);

    if (cords == NULL)
        return (3);
    if (win_lose_check(game_board[0], epid) == 1) {
        for (int a = 0; a < 12; a++)
            my_printf("%s", game_board[0][a]);
            game_board[1][0] = "\nenemy's positions:\n";
        for (int b = 0; b < 12; b++)
            my_printf("%s", game_board[1][b]);
        my_printf("\nEnemy won\n");
        *win = 2;
        free(buffer);
        free(cords);
        return (4);
    }
    return (get_buffer_free(game_board, buffer, end_file, epid));
}
