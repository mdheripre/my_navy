/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print functions for flags e, E, p, %
*/
#include "my.h"
#include <stdarg.h>

void printf_double_e(va_list ap, variable_t *variable)
{
    double_to_sn_lowcase(va_arg(ap, double), variable);
}

void printf_double_e_upcase(va_list ap, variable_t *variable)
{
    double_to_sn_upcase(va_arg(ap, double), variable);
}

void printf_b(va_list ap, variable_t *variable)
{
    dec_to_binary(va_arg(ap, unsigned long), variable);
}

void printf_pointer_address(va_list ap, variable_t *variable)
{
    print_ptr(va_arg(ap, void *), variable);
}

void printf_percent(va_list ap, variable_t *variable)
{
    my_putchar_f('%', variable);
}
