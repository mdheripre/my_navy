/*
** EPITECH PROJECT, 2023
** dec_to_binary.c
** File description:
** decimal to binary converter
*/

#include <stdlib.h>
#include "my.h"

void dec_to_binary(unsigned long dec_number, variable_t *variable)
{
    int *binary = malloc(sizeof(int) * 64);
    int i;

    if (dec_number == 0) {
        my_putnbr('0', variable);
        return;
    }
    for (i = 0; dec_number > 0; i++) {
        binary[i] = dec_number % 2;
        dec_number = dec_number / 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putnbr(binary[j], variable);
    }
}
