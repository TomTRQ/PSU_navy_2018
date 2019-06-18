/*
** EPITECH PROJECT, 2019
** game_start.c
** File description:
** navy
*/

#include "my.h"

int error_arg(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
        return (84);
    if (argc == 2 && open(argv[1], O_RDONLY) == -1)
        return (84);
    else if (argc == 3 && open(argv[2], O_RDONLY) == -1)
        return (84);
    if (argc == 3 && my_check_nbr(argv[1]) == 0)
        return (84);
    return (0);
}

int searching_player(char *argv[])
{
    int player = 0;

    if (open(argv[1], O_RDONLY) != -1)
        player = 0;
    else if (open(argv[2], O_RDONLY) != -1)
        player = 1;
    return (player);
}

void printing_h(char *argv[])
{
    if (argv[1] != NULL) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && \
        my_strlen(argv[1]) == 2) {
            my_printf("USAGE\n     ./navy [first_player_pid] " \
            "navy_positions\n");
            my_printf("DESCRIPTION\n     first_player_pid:  \
only for the 2nd player.  pid of the first player.\n");
            my_printf("     navy_positions:  file representing \
the positions of the ships.\n");
        }
    }
}

int game_start(int argc, char *argv[])
{
    int rtn = 0;
    int player = 0;
    int epid = 0;
    char ***game_board = NULL;

    printing_h(argv);
    if (error_arg(argc, argv) == 84 || pos_error(argc, argv) == 84)
        return (84);
    player = searching_player(argv);
    if (player == 0) {
        rtn = compute_player1(player, argv, game_board, epid);
        if (rtn == 84)
            return (84);
    }
    else if (player == 1) {
        rtn = compute_player2(player, argv, game_board, epid);
        if (rtn == 84)
            return (84);
    }
    return (rtn);
}
