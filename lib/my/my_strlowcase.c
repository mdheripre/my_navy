/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** function that put every char of a string in lower case
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i++){
        if (str[i] < 91 && str[i] > 64)
            str[i] = str[i] + 32;
    }
    return str;
}
