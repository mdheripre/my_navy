/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** function that reproduce printf functionality
*/
#include "my.h"
#include <stdarg.h>

void make_struct(variable_t *variable)
{
    variable->precision = 6;
    variable->width = 0;
    variable->count = 0;
    variable->prec_change = 0;
}

void print_condition(char letter, variable_t *variable)
{
    if (letter != '%')
        my_putchar_f(letter, variable);
}

void print_choice(char letter, va_list ap, variable_t *variable)
{
    int i;
    char flags[] = {"csdifFeExXounpbgG%"};

    for (i = 0; flags[i] != letter; i++)
        if (flags[i] == '\0')
            return;
    (option[i]).option(ap, variable);
}

int my_printf(const char *format, ...)
{
    variable_t variable;
    va_list ap;

    make_struct(&variable);
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            mod_check(format[i + 1], format, &i, &variable);
            print_choice(format[i + 1], ap, &variable);
            i++;
        } else
            print_condition(format[i], &variable);
    }
    va_end(ap);
    return variable.count;
}
