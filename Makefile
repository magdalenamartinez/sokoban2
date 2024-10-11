##
## June 2024
## Magdalena Martinez Sanchez
## MD5
## Makefile
##

NAME	=	MD5



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\


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
