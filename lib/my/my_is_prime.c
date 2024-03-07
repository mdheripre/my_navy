/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** function that determine if a number is prime or not
*/
#include "my.h"

int my_is_prime(int nb)
{
    if (nb == 2){
        return 1;
    }
    if (nb == 0 || nb == 1 || nb < 0){
        return 0;
    }
    for (int i = 2; i < nb; i++){
        if (nb % i == 0){
            return 0;
        }
    }
    return 1;
}
