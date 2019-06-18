/*
** EPITECH PROJECT, 2019
** connection file
** File description:
** navy
*/

#include "my.h"

int connector(int sig)
{
    static int epid = 0;

    if (sig != 0)
        epid = sig;
    if (sig == 0)
        return (epid);
    my_printf("enemy connected\n\n");
}

int check_buffer(char *buffer)
{
    if (buffer == NULL || my_strlen(buffer) == 1 || my_strlen(buffer) > 2)
        return (84);
    if (buffer[0] != '\0' && (buffer[0] < 65 || buffer[0] > 72))
        return (84);
    if (buffer[1] != '\0' && my_char_isnum(buffer[1]) == 0)
        return (84);
    if (buffer[1] - 48 == 0 || buffer[1] - 48 == 9)
        return (84);
    return (0);
}

void start_game_second_player(char ***game_board)
{
    for (int a = 0; a < 12; a++)
        my_printf("%s", game_board[0][a]);
    my_printf("\n");
    game_board[1][0] = "enemy's positions:\n";
    for (int b = 0; b < 12; b++)
        my_printf("%s", game_board[1][b]);
    my_printf("\nattack: ");
}

void handler2(int sig)
{
    write(1, "successfully connected\n\n", 25);
}

int printing_second_player_informations(char *argv[])
{
    int epid = my_convert_to_int(argv[1]);
    int kil = kill(epid, SIGUSR2);

    my_printf("my_pid: %d\n", getpid());
    if (kil != 0) {
        write(2, "wrong pid\n", 10);
        return (84);
    }
    signal(SIGUSR1, handler2);
    pause();
    return (epid);
}
