/*
** EPITECH PROJECT, 2018
** My_printf
** File description:
** Main file
*/

#include "../../include/my.h"

int counting_arg(char *str)
{
    int a = 0;
    int result = 0;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] == '%')
            result = result + 1;
    }
    return (result);
}

int flags(void(*tab[10])(va_list list), char *str, int a, va_list list)
{
    char *reference = "sdicbxXSupo";
    int b = 0;

    for (b = 0; reference[b] != '\0'; b++) {
        if (str[a + 1] == reference[b]) {
            tab[b](list);
        }
    }
    return (a++);
}

void printing(char *str, va_list list, void(*tab[11])(va_list list))
{
    int a = 0;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] != '%' && str[a - 1] != '%')
            my_putchar(str[a]);
        else if (str[a] == '%' && str[a + 1] == '%')
            my_putchar('%');
        else
            flags(tab, str, a, list);
    }
}

void my_printf(char *str, ...)
{
    int nbr = counting_arg(str);
    va_list list;
    void (*tab[11])(va_list list);

    tab[0] = my_putstrp;
    tab[1] = my_putnbrp;
    tab[2] = my_putnbrp;
    tab[3] = my_putcharp;
    tab[4] = my_binary;
    tab[5] = my_put_minhex;
    tab[6] = my_put_majhex;
    tab[7] = my_prints;
    tab[8] = my_unsigned_int;
    tab[9] = my_pointer_adress;
    tab[10] = my_octal;
    va_start(list, nbr);
    printing(str, list, tab);
    va_end(list);
}
