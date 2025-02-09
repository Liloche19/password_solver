#ifndef PASSWORD_H
    #define PASSWORD_H

    #define MAX_ASCII 126
    #define MIN_ASCII 32

// Help function
int print_help(int argc);

// File functions
char *get_file(char *file_path);

// Hash functions
char *get_hash_from_user(char *user);
char *get_param(char *expected);
int nb_dollars(char *str);

// Try password functions
int increment(char *mdp, int i);
int try_size(char *mdp, char *expected, char *param, int *comb);

#endif // PASSWORD_H
