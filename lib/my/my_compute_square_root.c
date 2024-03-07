/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** function that return the squareroot of a number given as argument
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int i;
    int a;

    a = 1;
    i = 0;
    while (nb != 0) {
        if (nb < 0) {
            return 0;
        }
        nb = nb - a;
        i++;
        a = a + 2;
    }
    return i;
}
