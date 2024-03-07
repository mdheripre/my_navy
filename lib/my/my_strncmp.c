/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** function compararing the sum of the ascii value in two string
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        n = my_strlen(s1) + my_strlen(s2);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
