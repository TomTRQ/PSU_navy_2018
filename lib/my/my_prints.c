/*
** EPITECH PROJECT, 2018
** S flag
** File description:
** my_printf
*/

#include "../../include/my.h"

void convert_to_octal(int nbr)
{
    int reste = 0;
    int retenu = 1;

    while (nbr != 0) {
        reste = reste + (nbr % 8) * retenu;
        nbr = nbr / 8;
        retenu = retenu * 10;
    }
}

void my_prints(va_list list)
{
    char *str = va_arg(list, char *);
    int reste = 0;
    int retenu = 1;
    int i = 0;

    for (;str[i] != '\0'; i++) {
        if (str[i] <= 31 || str[i] >= 127) {
            my_putchar(92);
            convert_to_octal(str[i]);
        }
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
    }
}
