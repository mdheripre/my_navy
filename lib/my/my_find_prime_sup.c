/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** function that return the smallest prime number greater than the argument
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1){
        nb++;
    }
    return nb;
}
