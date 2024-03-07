/*
** EPITECH PROJECT, 2023
** my_numlen.c
** File description:
** function that return the length of an integer
*/
#include "my.h"

int my_numlen(int nb, int *count)
{
    if (nb < 0)
        nb = -nb;
    if (nb >= 10) {
        my_numlen(nb / 10, count);
        (*count)++;
    }
    return *count;
}
