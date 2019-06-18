/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** All .h functions
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <dirent.h>
#include <signal.h>

//SRC PROTOTYPES

int stop_loop(char ***game_board, int *win, int epid);
int game_start(int argc, char *argv[]);
int searching_player(char *argv[]);
int error_arg(int argc, char *argv[]);
int connector(int sig);
int check_buffer(char *buffer);
int printing_first_player_informations(void);
int start_game_first_player(char ***map);
int game_first_player(int epid, char ***game_board, int *win);
int game_second_player(int epid, char ***game_board, int *win);
int printing_second_player_informations(char *argv[]);
int pos_error(int argc, char **argv);
int check_input(char **buffer, char ****game_board);
int mod_k(int epid);
int check_hit(void);
int check_entry(char *cord, char **map);
int ch_hit(int sig);
int compute_player1(int player, char **argv, char ***game_board, int epid);
int compute_player2(int player, char **argv, char ***game_board, int epid);
int win_lose_check(char **map, int epid);
int game_end(char ***game_board);

char *receive_cords(char *cords);
char *trans_cords(char *cords, int i, int j);
char *while_wrong_argument(char *buffer, int end_file);
char *get_next_line(int fd, int *end_file);
char **add_hit_miss_map(char **map, char letter, char number, char hit);
char **create_empty_map(void);
char **buffer_to_tab(char *buffer);
char **add_cordinates_to_map(char *buffer, char **map);
char ***creating_gameboard(int player, char **argv);

void start_game_second_player(char ***map);
void send_cords(int epid, char *buffer);
void printing_h(char *argv[]);
void f_miss(int sig, siginfo_t *siginfo, void *context);
void f_hit(int sig, siginfo_t *siginfo, void *context);
void handler1(int sig, siginfo_t *siginfo, void *context);
void rec1_handler(int sig, siginfo_t *siginfo, void *context);
void rec2_handler(int sig, siginfo_t *siginfo, void *context);
void set_recs(struct sigaction rec, struct sigaction rec2);
void print_hit_miss_on_map(char ***game_board, char *cords, int epid);
void print_check_hit(char *buffer, int epid, char ***game_board);

//LIB PROTOTYPES

char *my_strcpy(char *dest, char *src);
int my_compute_power_it(int nb, int p);
int my_check_nbr(char *str);
int my_char_isnum(char c);
int my_convert_to_int(char *str);
void my_unsigned_int(va_list list);
void my_prints(va_list list);
void my_printf(char *str, ...);
void my_putcharp(va_list list);
void my_putstrp(va_list list);
int my_putnbr(int nb);
void my_pointer_adress(va_list list);
void my_octal(va_list list);
void my_put_minhex(va_list list);
void my_put_majhex(va_list list);
void my_binary(va_list list);
void my_putchar(char c);
void my_putnbrp(va_list list);
void my_putstr(char *str);
char *my_revstr(char *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_putnbr(int nb);
int my_strlen(char *str);
int my_strnlen(char const *str);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char *src);
char *my_revstr(char *str);

#endif
