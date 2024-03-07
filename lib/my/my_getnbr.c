/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** return a number send as a string
*/

#include "my.h"

int number_sign(char const *str, int *p_sign)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '+')
            *p_sign = *p_sign * 1;
        if (str[i] == '-')
            *p_sign = *p_sign * (-1);
    }
    return *p_sign;
}

int max_min_check(long long nb)
{
    int int_max = 2147483647;
    int int_min = -2147483648;

    if (nb > int_max)
        return 0;
    if (nb < int_min)
        return 0;
    return 1;
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    long long nb = 0;

    number_sign(str, &sign);
    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - 48);
        if (str[i] < '0' || str[i] > '9')
            return (nb * sign);
        i++;
    }
    return (nb * sign);
}
