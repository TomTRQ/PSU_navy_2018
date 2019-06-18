/*
** EPITECH PROJECT, 2019
** compute.c
** File description:
** navy
*/

#include "my.h"

int compute_player1(int player, char **argv, char ***game_board, int epid)
{
    int win = 0;
    int rtn = 0;

    printing_first_player_informations();
    game_board = creating_gameboard(player, argv);
    epid = start_game_first_player(game_board);
    if (epid == 84)
        return (84);
    while (win == 0 && rtn == 0)
        rtn = game_first_player(epid, game_board, &win);
    return (rtn == 84 ? rtn : rtn - 3);
}

int compute_player2(int player, char **argv, char ***game_board, int epid)
{
    int win = 0;
    int rtn = 0;

    epid = printing_second_player_informations(argv);
    if (epid == 84)
        return (84);
    game_board = creating_gameboard(player, argv);
    while (win == 0 && rtn == 0)
        rtn = game_second_player(epid, game_board, &win);
    return (rtn == 84 ? rtn : rtn - 3);
}

int check_hit(void)
{
    int c_hit = 0;
    struct sigaction hit;
    struct sigaction miss;

    sigemptyset(&hit.sa_mask);
    sigemptyset(&miss.sa_mask);
    hit.sa_sigaction = &f_hit;
    miss.sa_sigaction = &f_miss;
    hit.sa_flags = SA_SIGINFO;
    miss.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &hit, NULL);
    sigaction(SIGUSR2, &miss, NULL);
    pause();
    return (ch_hit(0));
}

int stop_loop(char ***game_board, int *win, int epid)
{
    if (win_lose_check(game_board[0], epid) == 1) {
        for (int a = 0; a < 12; a++)
            my_printf("%s", game_board[0][a]);
            game_board[1][0] = "\nenemy's positions:\n";
        for (int b = 0; b < 12; b++)
            my_printf("%s", game_board[1][b]);
        my_printf("\nEnemy won\n");
        *win = 2;
        return (1);
    }
}

void print_hit_miss_on_map(char ***game_board, char *cords, int epid)
{
    if (check_entry(cords, game_board[0]) == 1) {
        my_printf("%s:  missed\n\n", cords);
        usleep(200);
        game_board[0] = add_hit_miss_map(game_board[0], cords[0], \
        cords[1], 'o');
        kill(epid, SIGUSR2);
        usleep(200);
    } else {
        my_printf("%s:  hit\n\n", cords);
        usleep(300);
        game_board[0] = add_hit_miss_map(game_board[0], cords[0], \
        cords[1], 'x');
        kill(epid, SIGUSR1);
        usleep(200);
    }
}