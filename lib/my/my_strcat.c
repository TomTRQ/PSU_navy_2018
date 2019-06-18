/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Task02
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char * temp = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    for (i = 0; dest[i] != '\0'; i++)
        temp[i] = dest[i];
    for (j = 0; src[j] != '\0'; j++)
        temp[i + j] = src[j];
    temp[i + j] = '\0';
    return (temp);
}
