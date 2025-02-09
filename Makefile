SRC	=	src/main.c\
		src/open_file.c\
		src/get_hash.c\
		src/try_password.c\
		src/help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	password_solver

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcrypt
	sudo chown root:root $(NAME)
	sudo chmod +s $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
