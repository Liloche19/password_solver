#include "../include/password.h"
#include <stdio.h>

int print_help(int argc)
{
    printf("Not enough argument !\n\n");
	printf("Usage :\n\t./crack_password USER\n");
    return (argc != 2) * 84;
}
