/*
** EPITECH PROJECT, 2018
** my_put_minhex
** File description:
** my_printf
*/

#include "../../include/my.h"

void my_put_minhex(va_list list)
{
    unsigned int n = va_arg(list, unsigned int);
    int i = 0;
    int reste = 0;
    char *hexa = malloc(sizeof(char) * n);

    while (n != 0) {
        reste = 0;
        reste = n % 16;
        if (reste < 10) {
            hexa[i] = reste + 48;
            i++;
        }
        if (reste >= 10) {
            hexa[i] = reste + 87;
            i++;
        }
        n = n / 16;
    }
    my_revstr(hexa);
    my_putstr(hexa);
}
