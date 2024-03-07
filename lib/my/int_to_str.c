/*
** EPITECH PROJECT, 2023
** int_to_str.c
** File description:
** int into str
*/

#include "my.h"
#include <stdlib.h>

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(int) * 8);
    int i = 0;
    int size = 0;
    int temp = nb;

    if (nb < 0) {
        str[0] = '-';
        nb = -nb;
        i = 1;
    }
    while (temp > 0) {
        temp /= 10;
        size++;
    }
    for (int j = size - 1; j >= i; j--) {
        str[j] = (nb % 10) + '0';
        nb /= 10;
    }
    str[size] = '\0';
    return str;
}
