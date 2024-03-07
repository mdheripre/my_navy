/*
** EPITECH PROJECT, 2023
** p_n_flags.c
** File description:
** print p and n flags
*/
#include "my.h"

void print_ptr_zero(char *str, variable_t *variable)
{
    int len = my_strlen(str) - 2;
    int zero_number = 0;

    if (len < variable->precision) {
        zero_number = variable->precision - len + 1;
        precision_zero(zero_number, variable);
    }
    variable->prec_change = 0;
}

void print_ptr(void *ptr, variable_t *variable)
{
    unsigned long address = (unsigned long)ptr;
    char hexa_chars[16] = "0123456789abcdef";
    int rem;
    char ptr_in_hexa[17];
    int i = 0;

    while (address != 0) {
        rem = address % 16;
        i++;
        ptr_in_hexa[i] = hexa_chars[rem];
        address = address / 16;
    }
    my_putstr_f("0x", variable);
    if (variable->prec_change != 0)
        print_ptr_zero(ptr_in_hexa, variable);
    for (int j = i - 1; j >= 0; j--) {
        my_putchar_f(ptr_in_hexa[j], variable);
    }
}
