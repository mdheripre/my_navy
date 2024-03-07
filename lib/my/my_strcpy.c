/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** copy a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
