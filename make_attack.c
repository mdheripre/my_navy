/*
** EPITECH PROJECT, 2024
** MAKE_ATTACK.C
** File description:
** file to get inputs from players and attack
*/

#include "include/my_navy.h"

int check_attack(char *line)
{
    if (line[0] < 'A' || line[0] > 'H')
        return -1;
    if (line[1] < '1' || line[1] > '8')
        return -1;
    return 0;
}

char *get_input(char *line)
{
    size_t len = 0;

    while (!line) {
        getline(&line, &len, stdin);
        if (my_strlen(line) != 3 ||
            check_attack(line) == -1) {
            my_printf("\nwrong position\n\n");
            my_printf("attack: ");
            line = NULL;
        }
    }
    return line;
}

int process_attack(int x, int y)
{
    int k = 0;

    k = x * 10 + y;
    return k;
}

int make_attack(int pid, char **enm_array)
{
    char *line = NULL;
    int k = 0;

    my_printf("attack: ");
    line = get_input(line);
    if (line != NULL)
        k = process_attack(line[0] % 64, line[1] - '0');
    for (int i = 0; i < k; i++) {
        kill(pid, SIGUSR1);
        usleep(1000);
    }
    free(line);
    my_printf("\n");
    kill(pid, SIGUSR2);
    get_hit_or_miss(k, enm_array);
    return 0;
}
