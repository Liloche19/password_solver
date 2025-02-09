#include "../include/password.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *get_hash_from_user(char *user)
{
	char *hash;
	char *file = get_file("/etc/shadow");
	char *elem;

	if (file == NULL)
		return NULL;
	elem = strtok(file, ":\n");
	while (elem != NULL){
		if (strcmp(elem, user) == 0){
			elem = strtok(NULL, ":\n");
			return elem;
		}
		elem = strtok(NULL, ":\n");
	}
	free(file);
	return NULL;
}

char *get_param(char *expected)
{
	int count = 0;
	int i = 0;
	char *param;
	int nb_dollar;

	if (expected == NULL)
		return NULL;
	nb_dollar = nb_dollars(expected);
	param = strdup(expected);
	while (count < nb_dollar && expected[i] != '\0'){
		if (expected[i] == '$')
			count++;
		i++;
	}
	if (count == nb_dollar)
		param[i - 1] = '\0';
	return param;
}

int nb_dollars(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        if (str[i] == '$')
            count++;
        i++;
    }
    return count;
}
