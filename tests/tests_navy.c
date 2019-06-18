/*
** EPITECH PROJECT, 2019
** tests_minishell.c
** File description:
** minishell1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//Tests Navy

Test(navy, add_hit_miss_map_1)
{
    char **map = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++)
        map[i] = malloc(sizeof(char) * 18);
    my_strcpy(map[0], "my positions:\n\0");
    my_strcpy(map[1]," |A B C D E F G H\n\0");
    my_strcpy(map[2], "-+---------------\n\0");
    my_strcpy(map[3], "1|. . . . . . . .\n\0");
    my_strcpy(map[4], "2|. . . . . . . .\n\0");
    my_strcpy(map[5], "3|. . . . . . . .\n\0");
    my_strcpy(map[6], "4|. . . . . . . .\n\0");
    my_strcpy(map[7], "5|. . . . . . . .\n\0");
    my_strcpy(map[8], "6|. . . . . . . .\n\0");
    my_strcpy(map[9], "7|. . . . . . . .\n\0");
    my_strcpy(map[10], "8|. . . . . . . .\n\0");
    add_hit_miss_map(map, 'D', '4', 'x');
    cr_assert(my_strcmp("4|. . . x . . . .\n\0", map[6], 0) == 0);
}

Test(navy, add_hit_miss_map_2)
{
    char **map = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++)
        map[i] = malloc(sizeof(char) * 18);
    my_strcpy(map[0], "my positions:\n\0");
    my_strcpy(map[1]," |A B C D E F G H\n\0");
    my_strcpy(map[2], "-+---------------\n\0");
    my_strcpy(map[3], "1|. . . . . . . .\n\0");
    my_strcpy(map[4], "2|. . . . . . . .\n\0");
    my_strcpy(map[5], "3|. . . . . . . .\n\0");
    my_strcpy(map[6], "4|. . . . . . . .\n\0");
    my_strcpy(map[7], "5|. . . . . . . .\n\0");
    my_strcpy(map[8], "6|. . . . . . . .\n\0");
    my_strcpy(map[9], "7|. . . . . . . .\n\0");
    my_strcpy(map[10], "8|. . . . . . . .\n\0");
    add_hit_miss_map(map, 'E', '1', 'o');
    cr_assert(my_strcmp("1|. . . . o . . .\n\0", map[3], 0) == 0);
}

Test(navy, check_buffer_1)
{
    char *buffer = NULL;

    cr_assert(check_buffer(buffer) == 84);
}

Test(navy, check_buffer_2)
{
    char *buffer = "Test";

    cr_assert(check_buffer(buffer) == 84);
}

Test(navy, check_buffer_3)
{
    char *buffer = "O";

    cr_assert(check_buffer(buffer) == 84);
}

Test(navy, check_buffer_4)
{
    char *buffer = "DA";

    cr_assert(check_buffer(buffer) == 84);
}

Test(navy, check_buffer_5)
{
    char *buffer = "I2";

    cr_assert(check_buffer(buffer) == 84);
}

Test(navy, printing_usage, .init = redirect_all_std)
{
    char *argv[] = {"./navy", "-h"};

    printing_h(argv);
    cr_assert_stdout_eq_str("USAGE");
    cr_assert_stdout_eq_str("     ./navy [first_player_pid] navy_positions");
    cr_assert_stdout_eq_str("DESCRIPTION");
    cr_assert_stdout_eq_str("     first_player_pid:  \
only for the 2nd player.  pid of the first player.");
    cr_assert_stdout_eq_str("     navy_positions:  \
file representing the positions of the ships.");
}

Test (navy, error_args_1)
{
    int argc = 2;
    char *argv[] = {"./navy", "pos2"};

    cr_assert(error_arg(argc, argv) == 84);
}

Test (navy, error_args_2)
{
    int argc = 3;
    char *argv[] = {"./navy", "pos1", "oui"};

    cr_assert(error_arg(argc, argv) == 84);
}

Test (navy, error_args_3)
{
    int argc = 4;
    char *argv[] = {"./navy", "OUI", "NON", "AH"};

    cr_assert(error_arg(argc, argv) == 84);
}

Test (navy, error_args_4)
{
    int argc = 3;
    char *argv[] = {"./navy", "234", "OUI"};

    cr_assert(error_arg(argc, argv) == 84);
}

Test (navy, error_args_5)
{
    int argc = 3;
    char *argv[] = {"./navy", "ah", "pos2"};

    cr_assert(error_arg(argc, argv) == 84);
}

Test (navy, error_args_6)
{
    int argc = 2;
    char *argv[] = {"./navy", "pos1"};

    cr_assert(error_arg(argc, argv) == 0);
}

Test (navy, searching_player_1)
{
    char *argv[] = {"./navy", "pos1"};

    cr_assert(searching_player(argv) == 0);
}

Test (navy, searching_player_2)
{
    char *argv[] = {"./navy", "2324", "pos2"};

    cr_assert(searching_player(argv) == 1);
}

Test (navy, start_game_1)
{
    int argc = 2;
    char *argv[] = {"./navy", "pos2"};

    cr_assert(game_start(argc, argv) == 84);
}

Test (navy, print_first_player_informations_1, .init = redirect_all_std)
{
    int pid = 100;

    printing_first_player_informations();
    cr_assert_stdout_eq_str("my_pid: 100\nwaiting for enemy connection...\n");
}

Test (navy, cordinates_error_1)
{
    char *cordinates[5] = {"2:C1:C3", "3:D4:F4", "4:B5:B8", "5:D7:H7", "TEST"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_2)
{
    char *cordinates[4] = {"2:C1:C3", "3:D4:F4", "4:B5:B8", "4:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_3)
{
    char *cordinates[4] = {"2.C1:C3", "3.D4:F4", "4:B5.B8", "5:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_4)
{
    char *cordinates[4] = {"2:Co:Cj", "3:D4:F4", "4:B5:B8", "5:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_5)
{
    char *cordinates[4] = {"2:C3:C1", "3:D4:F4", "4:B5:B8", "5:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_6)
{
    char *cordinates[4] = {"2:a1:b1", "3:D4:F4", "4:B5:B8", "5:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_7)
{
    char *cordinates[5] = {"2:C0:C9", "3:D4:F4", "4:B5:B8", "5:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, cordinates_error_8)
{
    char *cordinates[4] = {"2:C1:C3", "3:D4:F4", "4:B5:B8", "5:D7:H7"};

    cr_assert(cordinates_error(cordinates) == 0);
}

Test (navy, cordinates_error_9)
{
    char *cordinates[5] = {"2:A1:E3", "3:D4:F4", "4:B5:B8", "5:D7:H7", "TEST"};

    cr_assert(cordinates_error(cordinates) == 84);
}

Test (navy, pos_error_2_args)
{
    int argc = 2;
    char *argv[] = {"./navy", "pos1"};

    cr_assert(pos_error(argc, argv) == 0);
}

Test (navy, pos_error_3_args)
{
    int argc = 3;
    char *argv[] = {"./navy", "3123", "pos2"};

    cr_assert(pos_error(argc, argv) == 0);
}

Test (navy, fill_line)
{
    char *cordinates[4] = {"2:A1:E3", "3:D4:F4", "4:B1:C1", "5:D7:H7"};
    char **map = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++)
        map[i] = malloc(sizeof(char) * 18);
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
    fill_line(cordinates, map, 2);
    cr_assert(my_strcmp("1|. 4 4 . . . . .\n\0", map[3], 0) == 0);
}

Test (navy, fill_column)
{
    char *cordinates[4] = {"2:A1:E3", "3:D4:F4", "4:B1:B1", "5:D7:H7"};
    char **map = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++)
        map[i] = malloc(sizeof(char) * 18);
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
    fill_line(cordinates, map, 2);
    cr_assert(my_strcmp("1|. . . . . . . .\n\0", map[3], 0) == 1);
}

Test (navy, add_cordinates_to_map, .init = redirect_all_std)
{
    char *buffer = "2:A1:E3\n3:D4:F4\n4:B1:B1\n5:D7:H7";
    char **map = malloc(sizeof(char *) * 12);
    char **new_map = NULL;

    for (int i = 0; i != 12; i++)
        map[i] = malloc(sizeof(char) * 18);
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
    new_map = add_cordinates_to_map(buffer, map);
    cr_assert(my_strcmp("2|. . . x . . . .\n\0", new_map[4], 0) == 0);
}

Test (navy, mod_k_1)
{
    cr_assert(mod_k(9) == 0);
}

Test (navy, mod_k_2)
{
    cr_assert(mod_k(2) == 3);
}

Test (navy, ch_hit_sig_10)
{
    cr_assert(ch_hit(0) == 0);
}

Test (navy, connector_1, .init = redirect_all_std)
{
    cr_assert(connector(0) == 0);
}

Test (navy, connector_2, .init = redirect_all_std)
{
    connector(10);
}

Test (navy, check_buffer_wrong_second_char_buffer)
{
    cr_assert(check_buffer("D0") == 84);
}

Test (navy, check_buffer_right_argument)
{
    cr_assert(check_buffer("D2") == 0);
}

Test (navy, searching_first_player)
{
    char *argv[] = {"./navy", "pos1"};

    cr_assert(searching_player(argv) == 0);
}

Test (navy, searching_second_player)
{
    char *argv[] = {"./navy", "233", "pos2"};

    cr_assert(searching_player(argv) == 1);
}

//Tests librairie

Test (my_printf, simple_string , .init = redirect_all_std)
{
    my_printf("Just printing a simple string");
    cr_assert_stdout_eq_str("Just printing a simple string");
}

Test (my_printf, printing_simple_number , .init = redirect_all_std)
{
    int nbr = 10;

    my_printf("%d", nbr);
    cr_assert_stdout_eq_str("10");
}

Test (my_printf, printing_string, .init = redirect_all_std)
{
    char *str = "OUI";

    my_printf("%s", str);
    cr_assert_stdout_eq_str("OUI");
}

Test (my_printf, printing_char, .init = redirect_all_std)
{
    char letter = 'A';

    my_printf("%c", letter);
    cr_assert_stdout_eq_str("A");
}

Test (my_printf, decimal_to_hexadecimal_min, .init = redirect_all_std)
{
    int nbr = 1500;

    my_printf("%x", nbr);
    cr_assert_stdout_eq_str("5dc");
}

Test (my_printf, decimal_to_hexadecmial_maj, .init = redirect_all_std)
{
    int nbr = 1500;

    my_printf("%X", nbr);
    cr_assert_stdout_eq_str("5DC");
}

Test(my_printf, double_percent, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test (my_printf, percent_S, .init = redirect_all_std)
{
    char *str = "OUINON";

    my_printf("%S", str);
    cr_assert_stdout_eq_str("OUINON");
}

Test (my_printf, decimal_to_binary, .init = redirect_all_std)
{
    int nbr = 20;

    my_printf("%b", nbr);
    cr_assert_stdout_eq_str("10100");
}

Test (my_printf, unsigned_int, .init = redirect_all_std)
{
    int nbr = 654321;

    my_printf("%u", nbr);
    cr_assert_stdout_eq_str("654321");
}

Test (my_printf, multi_nbr_and_char, .init = redirect_all_std)
{
    int nbr = 20;
    char c = 'A';

    my_printf("%d %c", nbr, c);
    cr_assert_stdout_eq_str("20 A");
}

Test (my_printf, multi_nbr_and_str, .init = redirect_all_std)
{
    int nbr = 20;
    char *str = "Test";

    my_printf("%i %s", nbr, str);
    cr_assert_stdout_eq_str("20 Test");
}

Test (my_printf, multi_nbrs_and_char, .init = redirect_all_std)
{
    int nbr = 20;
    int nb = 1928;
    char c = 'O';

    my_printf("%d %i %c", nbr, nb, c);
    cr_assert_stdout_eq_str("20 1928 O");
}

Test (my_printf, multi_strings_and_char, .init = redirect_all_std)
{
    char *str = "This";
    char *st = "Is";
    char c = 'A';
    char *s = "Test";

    my_printf("%s %s %c %s", str, st, c, s);
    cr_assert_stdout_eq_str("This Is A Test");
}

Test (my_printf, multi_nbr_and_string, .init = redirect_all_std)
{
    int nbr = 20;
    char *str = "OUI123NON";

    my_printf("%s %d %s", str, nbr, str);
    cr_assert_stdout_eq_str("OUI123NON 20 OUI123NON");
}

Test (my_printf, multi_numbers, .init = redirect_all_std)
{
    int nbr = 20;
    int nb = 1200;
    int n = 42;

    my_printf("%d %d %d", nbr, nb, n);
    cr_assert_stdout_eq_str("20 1200 42");
}

Test (my_printf, multi_hexacedimal_and_str, .init = redirect_all_std)
{
    int nbr = 2000;
    char *str = "I love Segfaults";

    my_printf("%X %s", nbr, str);
    cr_assert_stdout_eq_str("7D0 I love Segfaults");
}

Test (my_printf, multi_hexadecimals, .init = redirect_all_std)
{
    int nbr = 42;

    my_printf("%X %x", nbr, nbr);
    cr_assert_stdout_eq_str("2A 2a");
}

Test (my_printf, multi_binary_and_string, .init = redirect_all_std)
{
    int nbr = 42;
    char *str = "Segfault is back";

    my_printf("%b %s", nbr, str);
    cr_assert_stdout_eq_str("101010 Segfault is back");
}

Test (my_printf, multi_binary_and_hexadecimal, .init = redirect_all_std)
{
    int nbr = 42;

    my_printf("%b %b %X %x", nbr, nbr, nbr, nbr);
    cr_assert_stdout_eq_str("101010 101010 2A 2a");
}

Test (my_printf, hard_test_01, .init = redirect_all_std)
{
    int nbr = 42;
    char *str = "OUINON";
    char *st = "NANI THE FUCK";
    char a = 'A';
    char b = 'H';

    my_printf("SEGFAULT %d %s %s 42 - 1 = 41 %c %c", nbr, str, st, a, b);
    cr_assert_stdout_eq_str("SEGFAULT 42 OUINON NANI THE FUCK 42 - 1 = 41 A H");
}

Test (my_printf, hard_test_02, .init = redirect_all_std)
{
    int nbr = 42;
    char a = 'O';
    char b = 'U';
    char c = 'I';
    char *str = "Hard test 02";

    my_printf("%d %s %X %c%c%c NANI %x %b", nbr, str, nbr, a, b, c, nbr, nbr);
    cr_assert_stdout_eq_str("42 Hard test 02 2A OUI NANI 2a 101010");
}

Test (my_strlen, basic_test, .init = redirect_all_std)
{
    char *str = "test str\0";
    int print = my_strlen(str);

    my_printf("%d\n", print);
    cr_assert_stdout_eq_str("8\n");
}

Test (my_strcat, basic_test, .init = redirect_all_std)
{
    char *str = "Bonjour";
    char *second = "Bonsoir";
    char *print = my_strcat(str, second);

    my_printf("%s\n", print);
    cr_assert_stdout_eq_str("BonjourBonsoir\n");
}

Test (my_check_nbr, wrong_number)
{
    char *nbr = "-10a";

    cr_assert(my_check_nbr(nbr) == 0);
}

Test (my_check_nbr, right_test_1)
{
    char *nbr = "42";

    cr_assert(my_check_nbr(nbr) == 1);
}

Test (my_check_nbr, right_test_negative)
{
    char *nbr = "-42";

    cr_assert(my_check_nbr(nbr) == 1);
}

Test (my_compute_power_it, first_wrong_test)
{
    cr_assert(my_compute_power_it(10, -1) == 0);
}

Test (my_compute_power_it, second_wrong_test)
{
    cr_assert(my_compute_power_it(2, 1000000) == 0);
}

Test (my_compute_power_it, p_equals_zero)
{
    cr_assert(my_compute_power_it(32, 0) == 1);
}

Test (my_compute_power_it, right_compute)
{
    int i = my_compute_power_it(10, 2);

    cr_assert_eq(i, 100);
}

Test (my_octal, simple_test, .init = redirect_all_std)
{
    int nbr = 20;

    my_printf("%o", nbr);
    cr_assert_stdout_eq_str("24");
}

Test (my_putnbrp, negative_test, .init = redirect_all_std)
{
    int i = -3;

    my_printf("%d", i);
    cr_assert_stdout_eq_str("-3");
}
