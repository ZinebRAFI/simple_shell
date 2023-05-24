#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

/*str_memo_print.c*/
int t_putchar(char c);
void t_puts(char *str);
int t_strlen(char *s);
char *r_strdup(char *str);
char *n_alloc_concats(char *name, char *sep, char *value);

/*prompts_conditions.c*/
void signal_handling(int sig_nbr);
void n_EOF(int leng, char *buffr);
void n_isatty(void);
/*string_exc.c*/
char **split_s_to_a(char *str, const char *dlmtr);
void execution(char **argv);
void *n_realloc(void *pntr, unsigned int prv_size, unsigned int n_size);
void free_arr_ptr(char **arra);

extern char **environ;


/**
 * struct list_of_path -data struct fot linked list containing PATH dir
 * @dir: direc in path
 * @p: ptr to the next node
 */
typedef struct list_of_path
{
	char *dir;
	struct list_of_path *p;
} list_of_path;

/*n_linked_paths.c*/
char *n_getenv(const char *name);
list_of_path *end_plus_node(list_of_path **tete, char *str);
/*setz_shell.c*/
list_of_path *linkedpaths(char *pt);
char *n_which(char *nomdoc, list_of_path *tete);
void free_memo_list(list_of_path *tete);

/**
 * struct ourbuilt - pointer to function with corresponding buildin command
 * @nom: buildin command
 * @fun: execute the buildin command
 */
typedef struct ourbuilt
{
	char *nom;
	void (*fun)(char **);
} ourbuilt;

/*builtinchecker*/
void exiting(char **arra);
void(*builtinchecker(char **arra))(char **arra);
int n_atoi(char *z);
void envr(char **arra);

/*builtinfun.c*/
void n_setenv(char **arra);
void n_unsetenv(char **arra);


#endif
