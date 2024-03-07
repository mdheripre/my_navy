/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** .h of mylib.a
*/
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef MACRO_MY_H
    #define MACRO_MY_H

typedef struct variable {
    int precision;
    int width;
    int count;
    int prec_change;
}variable_t;
char *my_strdup(char const *);
char **my_str_to_word_array(char *str);
int my_is_digit(char);
char my_chrup(char);
char my_chrdown(char);
int my_is_letter(char);
int myis_prime(int);
void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
void my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
int my_printf(const char *format, ...);
void make_struct(variable_t *variable);
char *my_strcpy_f(char *dest, char const *src, int stop);
char *my_strcpy_2(char *dest, char *src);
char *my_revstr_f(char *str);
int power_rec(int nb, int power);
int is_alpha(char c, variable_t *variable);
void my_putchar_f(char c, variable_t *variable);
void my_putnbr(unsigned long nb, variable_t *variable);
void my_put_nbr_f(int nb, variable_t *variable);
void my_putstr_f(char const *str, variable_t *variable);
void my_putstr_two(char *str, variable_t *variable);
void precision_zero(int n, variable_t *variable);
int my_numlen(int nb, int *count);
void my_put_double(double nb, variable_t *variable);
void my_put_double_modified(long double nb, variable_t *variable);
void dec_to_oct(int dec_number, variable_t *variable);
void print_ptr_zero(char *str, variable_t *variable);
void print_base_zero(char *str, variable_t *variable);
char dec_to_hex_upcase(unsigned long dec_number, variable_t *variable);
char dec_to_hex_lowcase(unsigned long dec_number, variable_t *variable);
void *signed_to_unsigned(int nb, variable_t *variable);
void print_ptr(void *ptr, variable_t *variable);
char *int_to_str(int nb);
int abs(int nb);
void mod_check(char letter, const char *format, int *current, variable_t *var);
int precision_modifier(const char *format, int *current);
void printf_char(va_list ap, variable_t *variable);
void printf_str(va_list ap, variable_t *variable);
void printf_int(va_list ap, variable_t *variable);
void printf_double(va_list ap, variable_t *variable);
void printf_octal(va_list ap, variable_t *variable);
void printf_unsigned_int(va_list ap, variable_t *variable);
void printf_hex_lowcase(va_list ap, variable_t *variable);
void printf_hex_upcase(va_list ap, variable_t *variable);
void printf_double_e(va_list ap, variable_t *variable);
void printf_double_e_upcase(va_list ap, variable_t *variable);
void printf_double_g_lowcase(va_list ap, variable_t *variable);
void printf_b(va_list ap, variable_t *variable);
void printf_g(va_list ap, variable_t *variable);
void printf_g_upcase(va_list ap, variable_t *variable);
void my_round(int decimal_part, int int_part, double nb, variable_t *variable);
void print_zero(int decimal_part, int count, variable_t *variable);
void printer(int exp, variable_t *variable);
void double_to_sn_lowcase(double nb, variable_t *variable);
void double_to_sn_upcase(double nb, variable_t *variable);
void my_put_double_two(double nb, variable_t *variable);
void double_to_sn_lowcase_two(double nb, variable_t *variable);
void dec_to_binary(unsigned long dec_number, variable_t *variable);
void printf_pointer_address(va_list ap, variable_t *variable);
void printf_count(va_list ap, variable_t *variable);
void printf_percent(va_list ap, variable_t *variable);
void my_put_g(double nb, variable_t *variable);
void my_put_g_upcase(double nb, variable_t *variable);
typedef void (*flag_type)(va_list, variable_t *);
typedef struct print_option {
    char letter;
    flag_type option;
}print_option_t;
static const print_option_t option[] = {
    {'c', &printf_char},
    {'s', &printf_str},
    {'d', &printf_int},
    {'i', &printf_int},
    {'f', &printf_double},
    {'F', &printf_double},
    {'e', &printf_double_e},
    {'E', &printf_double_e_upcase},
    {'x', &printf_hex_lowcase},
    {'X', &printf_hex_upcase},
    {'o', &printf_octal},
    {'u', &printf_unsigned_int},
    {'n', &printf_count},
    {'p', &printf_pointer_address},
    {'b', &printf_b},
    {'g', &printf_g},
    {'G', &printf_g_upcase},
    {'%', &printf_percent}
};
#endif
