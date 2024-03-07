/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** put a string into 2d array
*/

#include "my.h"

bool is_char(int c)
{
    if (c >= 32 && c <= 126) {
        return true;
    }
    return false;
}

int count_rows(char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((is_char(str[i]) == true) && (is_char(str[i + 1]) == false)) {
            j++;
        }
    }
    return j;
}

int count_columns(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if ((is_char(str[i]) == false)) {
            return i;
        }
    }
    return i;
}

char **my_str_to_word_array(char *str)
{
    int rows = count_rows(str);
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * rows);

    for (int i = 0; i < rows; i++) {
        j = 0;
        array[i] = malloc(sizeof(char) * (count_columns(&str[k]) + 1));
        while (is_char(str[k]) == true) {
            array[i][j] = str[k];
            j++;
            k++;
        }
        array[i][j] = '\0';
        while (str[k] && !is_char(str[k])) {
            k++;
        }
    }
    return array;
}
