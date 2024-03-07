/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** main file for my_navy
*/

#include "include/my_navy.h"

static void free_boat(boat_t *boat)
{
    boat_t *tmp = NULL;

    while (boat != NULL) {
        tmp = boat;
        boat = boat->next;
        free(tmp);
    }
}

static void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("\t./my_navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid: only for the 2nd player.");
    my_printf(" pid of the first player.\n");
    my_printf("\tnavy_positions: file representing");
    my_printf(" the positions of the ships.\n");
}

struct sigaction init_sigaction(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    return sa;
}

int main(int ac, char **av)
{
    struct sigaction sa = init_sigaction();
    int pid = 0;
    boat_t *boat;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return 0;
    }
    boat = malloc(sizeof(boat_t));
    if (ac == 2 && read_script(av[1], boat) == 0) {
        pid = player_1(&sa, boat);
    } else if (ac == 3 && read_script(av[2], boat) == 0) {
        pid = my_getnbr(av[1]);
        pid = player_2(pid, &sa, boat);
    } else {
        free(boat);
        return 84;
    }
    free_boat(boat);
    return pid;
}
