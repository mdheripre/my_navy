/*
** EPITECH PROJECT, 2023
** MY_STRSTR
** File description:
** ??
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}
