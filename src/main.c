#include "../include/password.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int solve_password(char *user)
{
    int comb = 0;
    int size = 0;
	int found = 0;
	char *expected;
	char *try_mdp;
	char *param;

	expected = get_hash_from_user(user);
	param = get_param(expected);
	if (param == NULL){
	    write(2, "The user does not exists or do not have a password !\n", 54);
	    return -1;
	}
	while (!found){
		size++;
		try_mdp = malloc(sizeof(char) * (size + 1));
		try_mdp[size] = '\0';
		for (int i = 0; i < size; i++)
			try_mdp[i] = MIN_ASCII;
		printf("Trying password of size : %d\n", size);
		found = try_size(try_mdp, expected, param, &comb);
		free(try_mdp);
	}
	free(param);
    return comb;
}

int main(int argc, char **argv)
{
	int comb = 0;

	if (argc != 2 || strcmp(argv[1], "-h") == 0)
		return print_help(argc);
	comb = solve_password(argv[1]);
	if (comb == -1)
	   return 84;
	printf("Tested solutions : %d\n", comb);
	return 0;
}
