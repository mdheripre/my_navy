/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** return 1 if every char are uppercase else return 0
*/
#include "my.h"

int my_str_isupper(char const *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if ((str[i] < 'A' || str[i] > 'Z'))
            return 0;
    }
    return 1;
}
