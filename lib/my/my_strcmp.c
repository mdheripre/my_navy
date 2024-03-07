/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** function that compare the sum of assci value of characters in a string
*/
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int sum1 = 0;
    int sum2 = 0;

    while (s1[i] != '\0') {
        sum1 = sum1 + s1[i];
        i++;
    }
    i = 0;
    while (s2[i] != '\0') {
        sum2 = sum2 + s2[i];
        i++;
    }
    if (sum1 > sum2)
        return 1;
    if (sum1 < sum2)
        return -1;
    return 0;
}
