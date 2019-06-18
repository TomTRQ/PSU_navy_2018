/*
** EPITECH PROJECT, 2018
** my_unsigned_int
** File description:
** my_printf
*/

#include "../../include/my.h"

void my_unsigned_int(va_list list)
{
    unsigned int nb = va_arg(list, unsigned int);

    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
