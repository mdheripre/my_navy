/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** return one if the string contain only letter else return zero
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if ((str[i] > 'Z' && str[i] < 'a') || str[i] > 'z' || str[i] < 'A')
            return 0;
    }
    return 1;
}
