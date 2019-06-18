/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Rev string function
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int a = 0;
    int count = 0;
    char nbr;

    while (str[a] != '\0')
        a++;
    while (count < a / 2) {
        nbr = str[count];
        str[count] = str[a - count - 1];
        str[a - count - 1] = nbr;
        count++;
    }
    str[a] = '\0';
    return (str);
}
