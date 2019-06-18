/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** To compute powers
*/

#include "my.h"

int my_compute_power_it(int nb, int p)
{
    int a = nb;
    int count;

    if (p < 0 || p > 100000)
        return (0);
    if (p == 0)
        return (1);
    for (count = 1; count < p; count++) {
        nb = nb * a;
    }
    return (nb);
}
