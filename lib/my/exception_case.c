/*
** EPITECH PROJECT, 2023
** exception_case.c
** File description:
** file that contains all the functions for the exception case
*/
#include <stdarg.h>
#include "my.h"

void mod_check(char letter, const char *format, int *current, variable_t *var)
{
    int tmp = 0;

    if (letter == '.') {
        tmp = precision_modifier(format, current);
        var->precision = tmp;
        var->prec_change += 1;
    }
}

int my_is_digit(char a)
{
    if (a >= '0' && a <= '9')
        return 1;
    return 0;
}

int precision_modifier(const char *format, int *current)
{
    int p = 0;
    int next = *current + 2;

    while (my_is_digit(format[next]) == 1) {
        p = (p * 10) + (format[next] - 48);
        next++;
    }
    (*current) = next - 1;
    return p;
}
