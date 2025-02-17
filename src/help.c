#include "../include/password.h"
#include <stdio.h>

int print_help(int argc)
{
    if (argc != 2)
        printf("Not enough argument !\n\n");
	printf("Usage :\t./password_solver USER\n");
    return (argc != 2) * 84;
}
