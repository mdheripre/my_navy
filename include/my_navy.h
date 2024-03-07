/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-maximilien.dheripre
** File description:
** header file for my_navy
*/

#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

#ifndef MY_NAVY_H
    #define MY_NAVY_H
typedef struct boat_s {
    struct boat_s *next;
    int size;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} boat_t;

int make_attack(int pid, char **enm_array);

int get_attack(int usr1, char **map, char **enm_array, int player);

void print_game(char **my_array, char **enm_array);

void get_hit_or_miss(int k, char **enm_array);

void signal_handler(int signo, siginfo_t *info, void *context);

int player_1(struct sigaction *sa, boat_t *boat);

int player_2(int pid, struct sigaction *sa, boat_t *boat);

int read_script(char *filepath, boat_t *boat);

void signal_handler(int signo, siginfo_t *info, void *context);

char **init_my_navy(boat_t *boat, int p);

int win_condition(char **my_array, char **enm_array, int player);

#endif
