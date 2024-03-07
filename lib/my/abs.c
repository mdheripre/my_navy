/*
** EPITECH PROJECT, 2023
** printf
** File description:
** return the absolute value of an integer
*/
#include "my.h"

int abs(int nb)
{
    if (nb < 0)
        return -nb;
    else
        return nb;
}
