##
## EPITECH PROJECT, 2018
## my_world Bootstrap
## File description:
## Makefile
##

SRC	=	./src/main.c							\
		./src/terrain_modelling_and_maths.c		\
		./src/terrain_rendering.c				\
		./src/event_manager.c

CFLAGS	=	-W -Wall -Wextra -Werror -I./lordsclib/include/ -I./include/

LDFLAGS	=	-L./lordsclib/ -llords_clib -lcsfml-graphics -lcsfml-window -lm

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	bootstrap

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -s -C ./lordsclib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	@make clean -C ./lordsclib/
	@rm -f *~
	@rm -f \#*\#
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C ./lordsclib/
	@rm -f $(NAME)

re:	fclean	all
