/*
** EPITECH PROJECT, 2023
** my_rev_str
** File description:
** function that return a string reversed
*/
#include "my.h"

char *my_strcpy_f(char *dest, char const *src, int stop)
{
    int i;

    for (i = 0; i < stop; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strcpy_2(char *dest, char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_revstr_f(char *str)
{
    char copy[my_strlen(str)+1];
    int j = my_strlen(str) - 1;

    my_strcpy_2(copy, str);
    for (int i = 0; j >= 0; j--){
        str[i] = copy[j];
        i++;
    }
    return str;
}

char *my_revstr(char *str)
{
    char copy[my_strlen(str)+1];
    int j = my_strlen(str) - 1;

    my_strcpy(copy, str);
    for (int i = 0; j >= 0; j--){
        str[i] = copy[j];
        i++;
    }
    return str;
}
