/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** print a number
*/
#include "my.h"

void my_put_nbr_f(int nb, variable_t *variable)
{
    if (nb < 0) {
        my_putchar_f('-', variable);
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr_f((nb / 10), variable);
    my_putchar_f((nb % 10 + 48), variable);
}

void my_putnbr(unsigned long nb, variable_t *variable)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar_f(nb + 48, variable);
    } else if (nb > 9) {
        my_put_nbr_f(nb / 10, variable);
        my_putchar_f(nb % 10 + 48, variable);
    }
}

void my_put_nbr(int nb)
{
    if (nb > 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
