/*
** EPITECH PROJECT, 2024
** MAP.C
** File description:
** file to get maps of my_navy
*/

#include "include/my_navy.h"

static void free_array(char **array)
{
    for (int i = 0; i < 4; i++) {
        free(array[i]);
    }
    free(array);
}

int set_boat2(char **array_map, boat_t *boat, int i)
{
    if (boat->start_y < boat->end_y) {
        if (array_map[boat->start_y + i][boat->start_x] != '.')
            return 0;
        array_map[boat->start_y + i][boat->start_x] = boat->size + '0';
    }
    if (boat->start_y > boat->end_y) {
        if (array_map[boat->start_y - i][boat->start_x] != '.')
            return 0;
        array_map[boat->start_y - i][boat->start_x] = boat->size + '0';
    }
    return 1;
}

int set_boat1(char **array_map, boat_t *boat, int i)
{
    if (!set_boat2(array_map, boat, i))
        return 0;
    if (boat->start_x < boat->end_x) {
        if (array_map[boat->start_y][boat->start_x + i] != '.')
            return 0;
        array_map[boat->start_y][boat->start_x + i] = boat->size + '0';
    }
    if (boat->start_x > boat->end_x) {
        if (array_map[boat->start_y][boat->start_x - i] != '.')
            return 0;
        array_map[boat->start_y][boat->start_x - i] = boat->size + '0';
    }
    return 1;
}

int set_boat(char **array_map, boat_t *boat)
{
    for (int i = 0; i < boat->size; i++) {
        if (!set_boat1(array_map, boat, i)) {
            return 0;
        }
    }
    return 1;
}

int get_ships(char **array_map, boat_t *boat)
{
    boat_t *tmp = boat;

    while (tmp != NULL) {
        if (!set_boat(array_map, tmp))
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

char **init_my_navy(boat_t *boat, int p)
{
    int fd = open("player_1_map", O_RDONLY);
    char *map;
    char **array_map;

    map = malloc(sizeof(char) * 72 + 1);
    if (read(fd, map, 72) == -1)
        return NULL;
    map[72] = '\0';
    array_map = my_str_to_word_array(map);
    if (p == 0) {
        if (!get_ships(array_map, boat)) {
            free_array(array_map);
            array_map = NULL;
        }
    }
    free(map);
    close(fd);
    return array_map;
}
