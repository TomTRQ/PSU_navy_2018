/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Compares two stringss
*/

#include "my.h"

int my_strcmp(char *s1, char *s2, int b)
{
    if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
        return (1);
    for (int i = 0; s2 != NULL && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (1);
    for (int i = 0; s1 != NULL && s1[i] != '\0'; i++)
        if (b == 1 && s2[i] != s1[i])
            return (1);
    return (0);
}
