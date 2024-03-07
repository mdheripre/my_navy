/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-maximilien.dheripre
** File description:
** function to play navy
*/

#include "include/my_navy.h"

void print_game(char **my_array, char **enm_array)
{
    my_printf("my navy:\n |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_printf("%c ", my_array[i][j]);
        }
        my_printf("\n");
    }
    my_printf("\n");
    my_printf("enemy navy:\n |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_printf("%c ", enm_array[i][j]);
        }
        my_printf("\n");
    }
    my_printf("\n");
}
