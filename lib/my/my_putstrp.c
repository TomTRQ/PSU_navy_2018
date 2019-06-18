/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putstrp(va_list list)
{
    char *str = va_arg(list, char *);
    int nbr = 0;
    int a = 0;

    if (str != NULL) {
        while (str[nbr] != '\0') {
            nbr++;
        }
        while (a < nbr) {
            my_putchar(str[a]);
            a++;
        }
    }
}
