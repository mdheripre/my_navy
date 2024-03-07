/*
** EPITECH PROJECT, 2023
** my_isprintable
** File description:
** return 1 when all the string is printable and return 0 if not
*/
#include "my.h"

int my_str_isprintable(char const *str)
{
    if (my_strlen(str) == 0)
        return 1;
    for (int i = 0; i < my_strlen(str) - 1; i++) {
        if ((str[i] < 20 || str[i] > 126))
            return 0;
    }
    return 1;
}
