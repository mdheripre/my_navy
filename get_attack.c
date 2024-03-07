/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-maximilien.dheripre
** File description:
** file for interpreting the attack
*/

#include "include/my_navy.h"

void print_player_1_map(int player, char **map, char **enm_array)
{
    if (player == 1)
        print_game(map, enm_array);
}

int get_attack(int usr1, char **map, char **enm_array, int player)
{
    unsigned int row = (usr1 % 10) - 1;
    unsigned int col = usr1 / 10 - 1;

    if (map[row][col] != '.' && map[row][col] !=
        'x' && map[row][col] != 'o') {
        map[row][col] = 'x';
        my_printf("result: %c%c:hit\n\n",
            (unsigned char)col + 'A', (unsigned char)row + '0' + 1);
        print_player_1_map(player, map, enm_array);
        return 1;
    } else {
        if (map[row][col] != 'x')
            map[row][col] = 'o';
        my_printf("result: %c%c:missed\n\n",
            (unsigned char)col + 'A', (unsigned char)row + '0' + 1);
        print_player_1_map(player, map, enm_array);
        return 0;
    }
}
