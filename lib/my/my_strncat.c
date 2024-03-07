/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** funtion that concatenates n characters of the src string
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);

    for (int j = 0; j < nb; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
