/*
** EPITECH PROJECT, 2019
** first_player_game.c
** File description:
** navy
*/

#include "my.h"

int printing_first_player_informations(void)
{
    int pid = getpid();

    my_printf("my_pid: %d\n", pid);
    my_printf("waiting for enemy connection...\n\n");
    return (pid);
}

int start_game_first_player(char ***game_board)
{
    int epid = 0;
    struct sigaction sigs;

    sigemptyset(&sigs.sa_mask);
    sigs.sa_sigaction = &handler1;
    sigs.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sigs, NULL);
    pause();
    epid = connector(0);
    if (kill(epid, SIGUSR1) != 0)
        return (84);
    return (epid);
}

void print_check_hit(char *buffer, int epid, char ***game_board)
{
    my_printf("%s: ", buffer);
    send_cords(epid, buffer);
    if (check_hit() == 1) {
        my_printf("hit\n\n");
        game_board[1] = add_hit_miss_map(game_board[1], buffer[0], \
        buffer[1], 'x');
    } else {
        my_printf("missed\n\n");
        game_board[1] = add_hit_miss_map(game_board[1], buffer[0], \
        buffer[1], 'o');
    }
}

void print_first_player_map(char ***game_board)
{
    for (int a = 0; a < 12; a++)
        my_printf("%s", game_board[0][a]);
    game_board[1][0] = "\nenemy's positions:\n";
    for (int b = 0; b < 12; b++)
        my_printf("%s", game_board[1][b]);
    my_printf("\nattack: ");
}

int game_first_player(int epid, char ***game_board, int *win)
{
    int end_file = 0;
    int c_hit = 0;
    char *buffer = malloc(sizeof(char) * 3);
    char *cords = malloc(sizeof(char) * 3);

    print_first_player_map(game_board);
    buffer = while_wrong_argument(buffer, end_file);
    if (buffer == NULL)
        return (84);
    print_check_hit(buffer, epid, game_board);
    if (game_end(game_board) == 1)
        return (3);
    cords = receive_cords(cords);
    print_hit_miss_on_map(game_board, cords, epid);
    if (stop_loop(game_board, win, epid) == 1)
        return (4);
    free(buffer);
    free(cords);
    return (0);
}
