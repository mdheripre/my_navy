/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** this function displays either an integer is negative or positive
*/
#include "my.h"

int my_isneg(int n)
{
    char positive;
    char negative;

    positive = 80;
    negative = 78;
    if (n >= 0){
        my_putchar(positive);
    } else {
        my_putchar(negative);
    }
    return (0);
}
