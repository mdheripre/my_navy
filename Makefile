##
## EPITECH PROJECT, 2023
## my_navy
## File description:
## makefile for my_navy
##

SRC =	main.c	\
		read_script.c	\
		signal.c	\
		map.c	\
		get_attack.c	\
		make_attack.c	\
		print_game.c	\
		win.c	\

OBJ = $(SRC:.c=.o)

NAME =	my_navy

CFLAGS += -g -Wall -Wextra -Llib/my -lmy

.PHONY: all lib run clean fclean re

all:	$(NAME)

$(NAME):	lib	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

lib:
	@echo "compiling lib"
	make -C lib/my  all
	make -C lib/my clean
	@echo "lib compiled !"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re :	fclean all
