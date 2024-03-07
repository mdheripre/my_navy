/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print functions for flags x, X, u, o
*/

#include <stdarg.h>
#include "my.h"

void printf_octal(va_list ap, variable_t *variable)
{
    dec_to_oct(va_arg(ap, int), variable);
}

void printf_unsigned_int(va_list ap, variable_t *variable)
{
    signed_to_unsigned(va_arg(ap, int), variable);
}

void printf_hex_lowcase(va_list ap, variable_t *variable)
{
    dec_to_hex_lowcase(va_arg(ap, int), variable);
}

void printf_hex_upcase(va_list ap, variable_t *variable)
{
    dec_to_hex_upcase(va_arg(ap, int), variable);
}

void printf_count(va_list ap, variable_t *variable)
{
    my_put_nbr_f(variable->count, variable);
}
