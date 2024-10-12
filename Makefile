##
## June 2024
## Magdalena Martinez Sanchez
## sokoban
## Makefile
##

NAME	=	my_sokoban



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/open.c	\
		src/map.c	\
		src/utilities.c	\
		src/struct.c	\


OBJ	=	$(SRC:.c=.o)


all: 	$(NAME)

$(NAME): 	$(OBJ)

		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) 

clean:
	rm -f $(NAME)


fclean: clean
	rm -f ./src/*.o

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
