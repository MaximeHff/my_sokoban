##
## EPITECH PROJECT, 2021
## B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
## File description:
## Makefile
##

SRC=	src/sokoban.c		\
		src/load_map.c		\
		src/tools.c			\
		src/error.c			\
		src/keybord.c		\
		src/event.c			\
		src/saving.c		\
		src/restart.c		\
		src/winorlose.c			\
		src/error_map.c		\

OBJ=	$(SRC:.c=.o)

NAME=	my_sokoban

# CFLAGS=		-Wall	-Wextra	 -pedantic

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib
	gcc $(SRC) -g -o $(NAME) -Llib -lmy -lncurses $(CFLAGS)

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/ fclean

re: fclean