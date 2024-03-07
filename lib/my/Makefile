##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile for libmy.a
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_put_nbr.c	\
		my_isneg.c	\
		my_swap.c	\
		my_getnbr.c	\
		my_sort_int_array.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_is_prime.c	\
		my_find_prime_sup.c	\
		my_strcpy.c	\
		my_revstr.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_strupcase.c	\
		my_str_isalpha.c\
		my_str_isnum.c	\
		my_str_islower.c\
		my_str_isupper.c\
		my_str_isprintable.c	\
		my_showstr.c	\
		my_showmem.c	\
		my_strcat.c	\
		my_strncat.c	\
		my_strlowcase.c	\
		my_strcapitalize.c	\
		abs.c	\
		dec_to_binary.c	\
		exception_case.c	\
		int_to_str.c	\
		my_numlen.c	\
		my_printf.c	\
		my_put_double.c	\
		my_put_double_sn.c	\
		my_put_g.c	\
		my_put_g_upcase.c	\
		p_n_flags.c	\
		power_rec.c	\
		print_functions_1.c	\
		print_functions_2.c	\
		print_functions_3.c	\
		print_functions_4.c	\
		unsigned_specifiers.c	\
		my_strdup.c	\
		my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)
	cp -r libmy.a ../libmy.a
	cp my.h	../../include

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../include/my.h
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
