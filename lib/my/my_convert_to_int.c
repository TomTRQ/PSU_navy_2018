/*
** EPITECH PROJECT, 2018
** my_convert_to_int
** File description:
** my_convert_to_int
*/

#include "my.h"

int my_convert_to_int(char *str)
{
    int a = 0;
    int result = 0;

    str = my_revstr(str);
    while (str[a] != '\0') {
        if (a >= 1)
            result = result + ((str[a] - 48) * my_compute_power_it(10, a));
        else
            result = result + ((str[a] - 48));
        a++;
    }
    return (result);
}
