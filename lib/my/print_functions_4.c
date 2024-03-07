/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print functions
*/

#include <stdarg.h>
#include "my.h"

void printf_g(va_list ap, variable_t *variable)
{
    my_put_g(va_arg(ap, double), variable);
}

void printf_g_upcase(va_list ap, variable_t *variable)
{
    my_put_g_upcase(va_arg(ap, double), variable);
}
