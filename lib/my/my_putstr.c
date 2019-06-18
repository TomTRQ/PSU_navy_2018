/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putstr(char *str)
{
    int nbr;
    int a;

    nbr = 0;
    a = 0;
    while (str[nbr] != '\0') {
        nbr++;
    }
    while (a < nbr) {
        my_putchar(str[a]);
        a++;
    }
}
