/*
** EPITECH PROJECT, 2023
** my_put_g
** File description:
** print %g flag
*/

#include "my.h"
#include "stdlib.h"

int count_zero(char *str, variable_t *variable)
{
    int i = my_strlen(str) - 1;
    int counter = 1;

    while (str[i] == '0'){
        counter *= 10;
        i--;
    }
    return counter;
}

void my_put_double_two(double nb, variable_t *variable)
{
    int count = 1;
    int int_part = nb;
    double tmp = (nb - int_part) * power_rec(10, variable->precision);
    int decimal_part = (float)tmp * 10;
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
        my_put_nbr_f(dem_part / count_zero(str, variable), variable);
    }
}

void double_to_sn_lowcase_two(double nb, variable_t *variable)
{
    int exp = 0;

    if (nb >= 1 || nb <= -1){
        while (nb > 10 || nb < -10){
            nb /= 10;
            exp++;
        }
        my_put_double_two(nb, variable);
        my_putstr_f("e+", variable);
        printer(exp, variable);
    } else {
        while (nb < 1 && nb > -1){
            nb *= 10;
            exp++;
        }
        my_put_double_two(nb, variable);
        my_putstr_f("e-", variable);
        printer(exp, variable);
    }
}

void my_put_g(double nb, variable_t *variable)
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
        double_to_sn_lowcase_two(nb, variable);
    else
        my_put_double_two(nb, variable);
}
