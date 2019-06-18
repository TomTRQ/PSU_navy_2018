/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

void my_putnbrp(va_list list)
{
    int nb = va_arg(list, int);

    if (nb > 9)
        my_putnbr(nb / 10);
    if (nb < 0)
        nb = nb * -1;
    my_putchar(nb % 10 + '0');
}
