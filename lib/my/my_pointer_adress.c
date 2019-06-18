/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "../../include/my.h"

void my_pointer_adress(va_list list)
{
    unsigned long int p = va_arg(list, unsigned long int);
    int adress;
    char *base;
    char res[9];
    int i = 8;

    adress = p;
    base = "0123456789abcdef";
    while ((adress / 16) > 0 || i >= 8) {
        res[i] = base[(adress % 16)];
        adress = adress / 16;
        i--;
    }
    res[i] = base[(adress % 16)];
    my_putchar('0');
    my_putchar('x');
    while (i < 9) {
        my_putchar(res[i]);
        i++;
    }
}
