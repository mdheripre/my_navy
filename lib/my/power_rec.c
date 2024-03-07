/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_REC
** File description:
** a recursive function
*/

int power_rec(int nb, int power)
{
    if (power < 0) {
        return 0;
    } else if (power == 0) {
        return 1;
    }
    return nb * power_rec(nb, power - 1);
}
