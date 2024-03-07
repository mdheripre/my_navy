/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-maximilien.dheripre
** File description:
** function to play navy
*/

#include "include/my_navy.h"

int game_state = -1;

static void free_array(char **my_array, char **enm_array)
{
    for (int i = 0; i < 8; i++) {
        free(my_array[i]);
    }
    free(my_array);
    for (int i = 0; i < 8; i++) {
        free(enm_array[i]);
    }
    free(enm_array);
}

void get_hit_or_miss(int k, char **enm_array)
{
    game_state = 3;
    pause();
    if (game_state == 0) {
        if (enm_array[(k % 10) - 1][k / 10 - 1] == '.')
            enm_array[(k % 10) - 1][k / 10 - 1] = 'o';
        my_printf("result: %c%c:missed\n\n",
            (char)((k / 10) + 64), (char)((k % 10) + '0'));
    }
    if (game_state == 1) {
        enm_array[(k % 10) - 1][k / 10 - 1] = 'x';
        my_printf("result: %c%c:hit\n\n",
            (char)((k / 10) + 64), (char)((k % 10) + '0'));
    }
    game_state = -1;
}

static int play_navy(int pid, char **my_array, char **enm_array, int player)
{
    static int k = 0;

    if (game_state == 0)
        k++;
    if (game_state == 1 && k > 0) {
        if (get_attack(k, my_array, enm_array, player) == 1) {
            kill(pid, SIGUSR2);
        } else {
            kill(pid, SIGUSR1);
        }
        if (win_condition(my_array, enm_array, player) == 1) {
            game_state = -2;
            return 1;
        }
        make_attack(pid, enm_array);
        k = 0;
    }
    return 2;
}

void signal_handler(int signo, siginfo_t *info, void *context)
{
    if (game_state == -1)
        game_state = info->si_pid;
    if (signo == SIGUSR1)
        game_state = 0;
    if (signo == SIGUSR2 && game_state != info->si_pid)
        game_state = 1;
}

static void wait_connection(int *pid, char **my_array, char **enm_array)
{
    my_printf("waiting for enemy...\n\n");
    pause();
    *pid = game_state;
    kill(*pid, SIGUSR1);
    my_printf("enemy connected\n\n");
    print_game(my_array, enm_array);
    make_attack(*pid, enm_array);
}

static int game_loop_p1(int pid,
    char **my_array,
    char **enm_array)
{
    int return_value = 0;

    while (1) {
        if (game_state == -1) {
            my_printf("waiting for enemy's attack...\n\n");
        }
        pause();
        return_value = play_navy(pid, my_array, enm_array, 1);
        if (return_value != 1)
            return_value = win_condition(my_array, enm_array, 2);
        if (return_value != 2)
            return return_value;
    }
    return return_value;
}

int player_1(struct sigaction *sa, boat_t *boat)
{
    char **my_array;
    char **enm_array;
    int pid = 0;

    my_array = init_my_navy(boat, 0);
    if (!my_array)
        return 84;
    enm_array = init_my_navy(boat, 1);
    sa->sa_handler = signal_handler;
    sigaction(SIGUSR2, sa, NULL);
    sigaction(SIGUSR1, sa, NULL);
    my_printf("my_pid: %d\n\n", getpid());
    wait_connection(&pid, my_array, enm_array);
    pid = game_loop_p1(pid, my_array, enm_array);
    free_array(my_array, enm_array);
    return pid;
}

static int game_loop_p2(int pid,
    char **my_array,
    char **enm_array)
{
    int return_value = 0;

    while (1) {
        pause();
        return_value = play_navy(pid, my_array, enm_array, 2);
        if (return_value != 1)
            return_value = win_condition(my_array, enm_array, 2);
        if (return_value != 2)
            return return_value;
        if (game_state == -1) {
            print_game(my_array, enm_array);
            my_printf("waiting for enemy's attack...\n\n");
        }
    }
    return return_value;
}

static void print_begin(char **my_array, char **enm_array)
{
    my_printf("my_pid: %d\n\n", getpid());
    my_printf("successfully connected to enemy\n\n");
    print_game(my_array, enm_array);
    my_printf("waiting for enemy's attack...\n\n");
}

int player_2(int pid, struct sigaction *sa, boat_t *boat)
{
    char **my_array;
    char **enm_array;

    my_array = init_my_navy(boat, 0);
    if (!my_array)
        return 84;
    enm_array = init_my_navy(boat, 1);
    sa->sa_handler = signal_handler;
    sigaction(SIGUSR2, sa, NULL);
    sigaction(SIGUSR1, sa, NULL);
    kill(pid, SIGUSR2);
    usleep(1000);
    if (game_state != 0)
        return 84;
    print_begin(my_array, enm_array);
    pid = game_loop_p2(pid, my_array, enm_array);
    free_array(my_array, enm_array);
    return pid;
}
