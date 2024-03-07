/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** function that display characters of a string one by one
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putstr_f(char const *str, variable_t *variable)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_f(str[i], variable);
}

void my_putstr_two(char *str, variable_t *variable)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_f(str[i], variable);
}
