/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** my_printf
*/

#include "../../include/my.h"

int my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return (nb);
}
