/*
** EPITECH PROJECT, 2023
** unsigned_specifiers.c
** File description:
** %o / %x / %X / %u
*/

#include "my.h"
#include <stdlib.h>

void print_base_zero(char *str, variable_t *variable)
{
    int len = my_strlen(str);
    int zero_number = 0;

    if (len < variable->precision) {
        zero_number = variable->precision - len + 1;
        precision_zero(zero_number, variable);
    }
    variable->prec_change = 0;
}

void dec_to_oct(int nb, variable_t *variable)
{
    unsigned int dec_nbr = nb;
    char *rem = malloc(sizeof(char) * 11);
    int i = 0;

    while (dec_nbr != 0) {
        rem[i] = dec_nbr % 8 + '0';
        dec_nbr = dec_nbr / 8;
        i++;
    }
    my_revstr(rem);
    if (variable->prec_change != 0)
        print_base_zero(rem, variable);
    my_putstr_f(rem, variable);
    free(rem);
}

char dec_to_hex_upcase(unsigned long dec_number, variable_t *variable)
{
    return 0;
}

char dec_to_hex_lowcase(unsigned long dec_number, variable_t *variable)
{
    return 0;
}

void *signed_to_unsigned(int nb, variable_t *variable)
{
    unsigned int nbr = 0;
    int count = 0;
    int len = my_numlen(nb, &count);

    if (variable->prec_change != 0)
        if (len < variable->precision)
            precision_zero(variable->precision - len, variable);
    variable->prec_change = 0;
    if (nb < 0){
        nbr = (4294967296 + nb);
        my_putnbr(nbr, variable);
    } else {
        my_putnbr(nb, variable);
    }
}
