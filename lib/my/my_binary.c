/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "../../include/my.h"

void my_binary(va_list list)
{
    unsigned int n = va_arg(list, unsigned int);
    int  binary = 0;
    int reste = 0;
    int i = 1;
    char *str;

    str = malloc(sizeof(char) * n);
    for (int j = 0; n != 0; i = i * 10) {
        reste = n % 2;
        n = n / 2;
        binary = binary + reste * i;
        if (reste == 0)
            str[j] = '0';
        if (reste == 1)
            str[j] = '1';
        j = j + 1;
    }
    my_revstr(str);
    my_putstr(str);
}
