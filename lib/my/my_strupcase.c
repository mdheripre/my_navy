/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** put every letter to the uppercase
*/
#include "my.h"

char *my_strupcase(char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i++){
        if (str[i] < 123 && str[i] > 96)
            str[i] = str[i] - 32;
    }
    return str;
}
