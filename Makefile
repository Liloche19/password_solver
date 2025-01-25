SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	crack_password

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcrypt
	sudo chown root:root crack_password
	sudo chmod +s crack_password

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
