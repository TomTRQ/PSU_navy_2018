/*
** EPITECH PROJECT, 2018
** my_octal
** File description:
** my_printf
*/

#include "../../include/my.h"

void my_octal(va_list list)
{
    int n = va_arg(list, int);
    int reste = 0;
    int retenu = 1;

    while (n != 0) {
        reste = reste + (n % 8) * retenu;
        n = n / 8;
        retenu = retenu * 10;
    }
    my_putnbr(reste);
}
