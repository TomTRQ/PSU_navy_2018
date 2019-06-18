/*
** EPITECH PROJECT, 2018
** main_file
** File description:
** GetNextLine
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

char *my_realloc(char *print, char *buffer)
{
    char *new;
    int i = 0;
    int nbr = 0;

    for (; print != NULL && print[nbr] != '\0'; nbr++);
    if (print == NULL)
        nbr = 1;
    new = malloc(sizeof(char) * (nbr + 2));
    while (print != NULL && print[i] != '\0') {
        new[i] = print[i];
        i++;
    }
    new[i] = buffer[0];
    new[i + 1] = '\0';
    return (new);
}

void compute_drphil(char *temp, int *end_file, int *end)
{
    if ((*end_file) == 0) {
        (*end_file) = -1;
        (*end) = 1;
    }
    if (temp[0] == '\n') {
        (*end) = 1;
    }
}

char *get_next_line(int fd, int *end_file)
{
    char *temp;
    char *str = NULL;

    for (int end = 0; end == 0;) {
        temp = malloc(sizeof(char) * 1);
        if (temp == NULL) {
            (*end_file) = -1;
            return (NULL);
        }
        (*end_file) = read(fd, temp, 1);
        if ((*end_file) == -1)
            return (NULL);
        compute_drphil(temp, end_file, &end);
        if (end == 0)
            str = my_realloc(str, temp);
        free(temp);
    }
    if (str == NULL)
        return (NULL);
    return (str);
}
