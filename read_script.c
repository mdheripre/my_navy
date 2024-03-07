/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-maximilien.dheripre
** File description:
** file for checking if script is valid
*/

#include "include/my_navy.h"

static void free_array(char **array)
{
    for (int i = 0; i < 4; i++) {
        free(array[i]);
    }
    free(array);
}

static void malloc_boat(boat_t *boat, int len)
{
    boat_t *tmp = boat;

    tmp->size = 0;
    for (int i = 0; i < (len - 1); i++) {
        tmp->next = malloc(sizeof(boat_t));
        tmp = tmp->next;
        tmp->size = 0;
    }
    tmp->next = NULL;
}

static int check_boats_sizes(char **array, int i)
{
    for (int j = i + 1; j < 4; j++) {
        if (array[i][0] == array[j][0])
            return 0;
    }
    return 1;
}

static int check_boats(char **array)
{
    int size = 0;

    for (int i = 0; i < 4; i++) {
        if (array[i][0] < '2' || array[i][0] > '5')
            return 0;
        if (!check_boats_sizes(array, i))
            return 0;
        size = array[i][2] - array[i][5];
        if (size == 0)
            size = array[i][3] - array[i][6];
        if (size < 0)
            size = -size;
        size++;
        if (size != (array[i][0] - '0'))
            return 0;
    }
    return 1;
}

static int check_char_order(char **array)
{
    for (int i = 0; i < 4; i++) {
        if (array[i][0] < '2' || array[i][0] > '5' || array[i][1] != ':' ||
            array[i][2] < 'A' || array[i][2] > 'H' || array[i][3] < '1'
            || array[i][3] > '8' || array[i][4] != ':' || array[i][5] < 'A'
            || array[i][5] > 'H' || array[i][6] < '1' || array[i][6] > '8') {
                return 0;
            }
        if (array[i][2] != array[i][5] && array[i][3] != array[i][6])
                return 0;
    }
    return 1;
}

static int is_script_valid(char *buffer, boat_t *boat)
{
    int len = 0;
    char **array;

    for (int i = 0; buffer[i] != '\n'; i++)
        len++;
    if (len != 7)
        return 1;
    array = my_str_to_word_array(buffer);
    if (!check_char_order(array)) {
        free_array(array);
        return 1;
    }
    len = check_boats(array);
    free_array(array);
    if (!len)
        return 1;
    malloc_boat(boat, 4);
    return 0;
}

static void retrieve_boat(char *buffer, boat_t *boat)
{
    boat_t *tmp = boat;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ':' && buffer[i + 3] == ':') {
            tmp->size = (buffer[i - 1] - 48);
            tmp->start_x = (buffer[i + 1] - 65);
            tmp->start_y = (buffer[i + 2] - 49);
            tmp->end_x = (buffer[i + 4] - 65);
            tmp->end_y = (buffer[i + 5] - 49);
            tmp = tmp->next;
        }
    }
    free(buffer);
}

static int read_script1(int size, char *buffer, boat_t *boat, int fd)
{
    if (size == -1 || size != 32 || !buffer) {
        close(fd);
        free(buffer);
        return 1;
    }
    buffer[size] = '\0';
    if (is_script_valid(buffer, boat) == 1) {
        close(fd);
        free(buffer);
        return 1;
    }
    return 0;
}

int read_script(char *filepath, boat_t *boat)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    int size = 0;
    size_t len = 33;

    if (fd == -1)
        return 1;
    buffer = malloc(sizeof(char) * 32 + 1);
    size = read(fd, buffer, len);
    if (read_script1(size, buffer, boat, fd) == 1)
        return 1;
    retrieve_boat(buffer, boat);
    close(fd);
    return 0;
}
