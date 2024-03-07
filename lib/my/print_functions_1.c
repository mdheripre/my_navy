/*
** EPITECH PROJECT, 2023
** my_prinf
** File description:
** print functions for c, s, d ,i, f flags
*/
#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

void precision_zero(int n, variable_t *variable)
{
    for (; n != 1; n--)
        my_putchar_f('0', variable);
}

void printf_char(va_list ap, variable_t *variable)
{
    my_putchar_f(va_arg(ap, int), variable);
}

void printf_str(va_list ap, variable_t *variable)
{
    int stop = 0;
    char *dest = malloc(sizeof(char) * stop + 1);
    char const *str = va_arg(ap, char *);
    int len = my_strlen(str);

    if (variable->prec_change != 0)
        if (len > variable->precision) {
            stop = variable->precision;
            my_strcpy_f(dest, str, stop);
            my_putstr_two(dest, variable);
            free(dest);
            return;
        }
    variable->prec_change = 0;
    my_putstr_f(str, variable);
}

void printf_int(va_list ap, variable_t *variable)
{
    int nb = va_arg(ap, int);
    int count = 0;
    int len = my_numlen(nb, &count);

    if (variable->prec_change != 0)
        if (len < variable->precision)
            precision_zero(variable->precision - len, variable);
    variable->prec_change = 0;
    my_put_nbr_f(nb, variable);
}

void printf_double(va_list ap, variable_t *variable)
{
    my_put_double(va_arg(ap, double), variable);
}
