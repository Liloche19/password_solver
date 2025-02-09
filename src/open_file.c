#include "../include/password.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
