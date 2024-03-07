/*
** EPITECH PROJECT, 2023
** my_put_double
** File description:
** function that print a double
*/

#include <unistd.h>
#include "my.h"

void my_round(int decimal_part, int int_part, double nb, variable_t *variable)
{
    if (nb >= 0)
        my_put_nbr_f(int_part + 1, variable);
    if (nb <= 0)
        my_put_nbr_f(int_part - 1, variable);
    my_putchar_f('.', variable);
    my_putchar_f('0', variable);
}

void print_zero(int decimal_part, int count, variable_t *variable)
{
    int len = my_numlen(decimal_part, &count);
    int missing_zero = 0;

    if (len < variable->precision)
        missing_zero = variable->precision - len;
    for (; missing_zero > 0; missing_zero--)
        my_putchar_f('0', variable);
}

void my_put_double(double nb, variable_t *variable)
{
    int count = 1;
    int int_part = nb;
    double tmp = (nb - int_part) * power_rec(10, variable->precision);
    int decimal_part = (float) tmp * 10;
    char *str = int_to_str(abs(decimal_part));
    int dem_part = decimal_part < 0 ? -decimal_part : decimal_part;

    if (str[variable->precision] >= '5')
        dem_part += ':' - str[variable->precision];
    if (dem_part >= power_rec(10, variable->precision + 1)){
        my_round(0, int_part, nb, variable);
        print_zero(0, count, variable);
    } else {
        if (nb < 0 && nb > -1)
            my_putchar_f('-', variable);
        my_put_nbr_f(int_part, variable);
        my_putchar_f('.', variable);
        print_zero(dem_part / 10, count, variable);
        my_put_nbr_f(dem_part / 10, variable);
    }
}
