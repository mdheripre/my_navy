/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** this function swap two integer value
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = 0;
    c = *b;
    *b = *a;
    *a = c;
}
