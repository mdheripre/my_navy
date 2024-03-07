/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** function that counts and returns the number of char in a string
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
