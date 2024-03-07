/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** function that print a character
*/
#include "my.h"
#include "unistd.h"

void my_putchar_f(char c, variable_t *variable)
{
    write(1, &c, 1);
    variable->count += 1;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
