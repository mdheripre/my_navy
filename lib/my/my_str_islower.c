/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** return 1 if string only contain low case letter else return 0
*/
#include "my.h"

int my_str_islower(char const *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if ((str[i] < 'a' || str[i] > 'z'))
            return 0;
    }
    return 1;
}
