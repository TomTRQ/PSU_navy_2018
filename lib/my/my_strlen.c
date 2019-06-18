/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int nbr = 0;

    while (str[nbr] != '\0')
        nbr++;
    return (nbr);
}
