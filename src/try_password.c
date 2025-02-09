#include "../include/password.h"
#include <crypt.h>
#include <string.h>
#include <stdio.h>

int increment(char *mdp, int i)
{
	if (mdp[i] == '\0')
		return 1;
	if (mdp[i] == MAX_ASCII){
		mdp[i] = MIN_ASCII;
		return increment(mdp, i + 1);
	}
	mdp[i] += 1;
	return 0;
}

int try_size(char *mdp, char *expected, char *param, int *comb)
{
	char *hash;

	while (!increment(mdp, 0)){
		(*comb)++;
		hash = crypt(mdp, param);
		if (strcmp(hash, expected) == 0){
			printf("Solution : [%s]\n", mdp);
			return 1;
		}
	}
	return 0;
}
