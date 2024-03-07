/*
** EPITECH PROJECT, 2023
** my_put_double_sn.c
** File description:
** print double in scientific notation
*/

#include "my.h"

void printer(int exp, variable_t *variable)
{
    if (exp < 10)
        my_putchar_f('0', variable);
    my_put_nbr_f(exp, variable);
}

void double_to_sn_lowcase(double nb, variable_t *variable)
{
    int exp = 0;

    if (nb >= 1 || nb <= -1){
        while (nb > 10 || nb < -10){
            nb /= 10;
            exp++;
        }
        my_put_double(nb, variable);
        my_putstr_f("e+", variable);
        printer(exp, variable);
    } else {
        while (nb < 1 && nb > -1){
            nb *= 10;
            exp++;
        }
        my_put_double(nb, variable);
        my_putstr_f("e-", variable);
        printer(exp, variable);
    }
}

void double_to_sn_upcase(double nb, variable_t *variable)
{
    int exp = 0;

    if (nb >= 1 || nb <= -1) {
        while (nb > 10 || nb < -10) {
            nb /= 10;
            exp++;
        }
        my_put_double(nb, variable);
        my_putstr_f("E+", variable);
        printer(exp, variable);
    } else {
        while (nb < 1 && nb > -1) {
            nb *= 10;
            exp++;
        }
        my_put_double(nb, variable);
        my_putstr_f("E-", variable);
        printer(exp, variable);
    }
}
