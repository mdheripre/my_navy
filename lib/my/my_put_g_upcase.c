/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** print %G flag
*/

#include "my.h"

void double_to_sn_upcase_two(double nb, variable_t *variable)
{
    int exp = 0;

    if (nb >= 1 || nb <= -1){
        while (nb > 10 || nb < -10){
            nb /= 10;
            exp++;
        }
        my_put_double_two(nb, variable);
        my_putstr_f("E+", variable);
        printer(exp, variable);
    } else {
        while (nb < 1 && nb > -1){
            nb *= 10;
            exp++;
        }
        my_put_double_two(nb, variable);
        my_putstr_f("E-", variable);
        printer(exp, variable);
    }
}

void my_put_g_upcase(double nb, variable_t *variable)
{
    double nbr = nb;
    int exp = 0;

    if (nb >= 1 || nb <= -1) {
        while (nbr > 10 || nbr < -10) {
            nbr /= 10;
            exp++;
        }
    } else {
        while (nbr < 1 && nbr > -1){
            nbr *= 10;
            exp--;
        }
    }
    if (exp < -4 || -exp > variable->precision)
        double_to_sn_upcase_two(nb, variable);
    else
        my_put_double_two(nb, variable);
}
