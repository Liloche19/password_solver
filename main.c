#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ASCII 126
#define MIN_ASCII 32

char *get_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    unsigned long size = 0;
    char *buffer;
    struct stat stat_file;

    if (fd == -1)
        return NULL;
    if (stat(file_path, &stat_file) != 0)
        return NULL;
    size = stat_file.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL || read(fd, buffer, size) == -1)
        return NULL;
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

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
	return hash;
}

char *get_param(char *expected)
{
	int count = 0;
	int i = 0;
	char *param;

	if (expected == NULL)
		return NULL;
	param = strdup(expected);
	while (count < 4 && expected[i] != '\0'){
		if (expected[i] == '$')
			count++;
		i++;
	}
	if (count == 4)
		param[i - 1] = '\0';
	return param;
}

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

int main(int argc, char **argv)
{
	int size = 0;
	int comb = 0;
	int found = 0;
	char *expected;
	char *try_mdp;
	char *param;

	if (argc != 2){
		printf("Not enough argument !\n\n");
		printf("Usage :\n\t./crack_password USER\n");
		return 84;
	}
	expected = get_hash_from_user(argv[1]);
	param = get_param(expected);
	if (param == NULL)
		return 84;
	while (!found){
		size++;
		try_mdp = malloc(sizeof(char) * (size + 1));
		try_mdp[size] = '\0';
		for (int i = 0; i < size; i++)
			try_mdp[i] = MIN_ASCII;
		printf("Size : %d\n", size);
		found = try_size(try_mdp, expected, param, &comb);
		free(try_mdp);
	}
	printf("Tested solutions : %d\n", comb);
	free(param);
	return 0;
}
