SRC	=	src/main.c\
		src/open_file.c\
		src/get_hash.c\
		src/try_password.c\
		src/help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	password_solver

FLAGS	=	-g

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
DEFAULT=\033[0m

all:	$(OBJ)
	@echo ""
	@echo -e "$(YELLOW)Compiling The program...$(DEFAULT)"
	@gcc -o $(NAME) $(OBJ) -lcrypt
	@echo -e "$(GREEN)Program compiled !$(DEFAULT)"
	@echo -e "$(YELLOW)Asking for root permissions:$(DEFAULT)"
	@sudo chown root:root $(NAME)
	@sudo chmod +s $(NAME)
	@echo -e "$(GREEN)Program has now root access$(DEFAULT)"
	@echo ""
	@echo -e "$(GREEN)Program ready to use !$(DEFAULT)"
	@echo -e "$(CYAN)For more informations: $(DEFAULT)./$(NAME) -h"
	@echo ""

clean:
	@echo ""
	@echo -e "$(YELLOW)Cleaning the objects files...$(DEFAULT)"
	@rm -f $(OBJ)
	@echo -e "$(GREEN)Objects files cleaned !$(DEFAULT)"
	@echo ""

fclean:	clean
	@echo -e "$(YELLOW)Cleaning all binary files...$(DEFAULT)"
	@rm -f $(NAME)
	@echo -e "$(GREEN)All binary files cleaned !$(DEFAULT)"
	@echo ""

%.o: %.c
	@gcc -c $< -o $@

re:	fclean
	@echo -e "$(CYAN)Recompiling the program...$(DEFAULT)"
	@make --no-print-directory

debug:
	rm -f $(OBJ)
	rm -f $(NAME)
	make $(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS) -lcrypt
	sudo chown root:root $(NAME)
	sudo chmod +s $(NAME)
