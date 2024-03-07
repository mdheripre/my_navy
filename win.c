/*
** EPITECH PROJECT, 2024
** B_PSU_100_LIL_1_1_navy_maximilien_dheripre
** File description:
** file for win condition
*/

#include "include/my_navy.h"

void count_x(char **array, int i, int k, int *count)
{
    if (array[i][k] == 'x')
        *count += 1;
}

void parse_map(char **array, int *count)
{
    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {
            count_x(array, i, k, count);
        }
    }
}

int win_condition(char **my_array, char **enm_array, int player)
{
    int count = 0;

    parse_map(enm_array, &count);
    if (count == 14) {
        print_game(my_array, enm_array);
        my_printf("I won\n");
        return 0;
    }
    count = 0;
    parse_map(my_array, &count);
    if (count == 14) {
        if (player == 1) {
            my_printf("Enemy won\n");
            return 1;
        }
        print_game(my_array, enm_array);
        my_printf("Enemy won\n");
        return 1;
    }
    return 2;
}
