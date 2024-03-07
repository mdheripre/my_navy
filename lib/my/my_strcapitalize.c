/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** capitalize the first letter of every word in a string
*/
#include "my.h"

char my_chrup(char a)
{
    if (a <= 'z' && a >= 'a')
        a = a - 32;
    return a;
}

char my_chrdown(char a)
{
    if (a < 91 && a > 64)
        a = a + 32;
    return a;
}

int my_is_letter(char b)
{
    if ((b < 123 && b > 96) || (b < 91 && b > 64))
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i;

    if (my_is_letter(str[0]) == 1 && str[0] <= 122 && str[0] >= 97)
        str[0] = str[0] - 32;
    for (i = 1; i < my_strlen(str) - 1; i++) {
        if (str[i] == ' ')
            str[i + 1] = my_chrup(str[i + 1]);
        if (my_is_letter(str[i]) == my_is_letter(str[i - 1]))
            str[i] = my_chrdown(str[i]);
        if (my_is_digit(str[i]) == my_is_letter(str[i + 1]))
            str[i + 1] = my_chrdown(str[i + 1]);
        if (str[i] == '+' && my_is_letter(str[i + 1]) == 1)
            str[i + 1] = my_chrup(str[i + 1]);
        if (str[i] == '-' && my_is_letter(str[i + 1]) == 1)
            str[i + 1] = my_chrup(str[i + 1]);
    }
    return str;
}
