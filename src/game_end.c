/*
** EPITECH PROJECT, 2019
** game_end.c
** File description:
** Navy's end game algorithm
*/

#include "my.h"

int compute_loss(int sig)
{
    static int win = 0;

    if (sig == 10)
        win = 1;
    if (sig == 12)
        win = 0;
    if (sig == 9)
        return (win);
}

void win_handler(int sig)
{
    compute_loss(10);
}

void lose_handler(int sig)
{
    compute_loss(12);
}

int game_end(char ***game_board)
{
    signal(SIGUSR1, win_handler);
    signal(SIGUSR2, lose_handler);
    pause();
    if (compute_loss(9) == 1) {
        for (int a = 0; a < 12; a++)
            my_printf("%s", game_board[0][a]);
            game_board[1][0] = "\nenemy's positions:\n";
        for (int b = 0; b < 12; b++)
            my_printf("%s", game_board[1][b]);
        my_printf("\nI won\n");
        return (1);
    }
    return (0);
}