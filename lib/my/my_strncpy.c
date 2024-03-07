/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** function that copy n character from a string to another
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
    if (n > my_strlen(src))
        dest[i] = '\0';
    return dest;
}
