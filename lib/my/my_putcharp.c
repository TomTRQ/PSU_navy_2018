/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_putchar
*/

#include "../../include/my.h"

void my_putcharp(va_list list)
{
    char c = va_arg(list, int);

    write(1, &c, 1);
}
