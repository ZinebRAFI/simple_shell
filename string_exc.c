#include "shell.h"


/**
 * split_s_to_a -a function that splits a str
 * to  make it into array of ptrs then to words
 * @str:arg str to split
 * @dlmtr:arg delimiter or words
 * Return: array of ptrs to words
 */

char **split_s_to_a(char *str, const char *dlmtr)
{
	int s, z;
	char **arra;
	char *tkn;
	char *cp;

	cp = malloc(t_strlen(str) + 1);
	if (cp == NULL)
	{
		perror(n_getenv("_"));
		return (NULL);
	}
	s = 0;
	while (str[s])
	{
		cp[s] = str[s];
		s++;
	}
	cp[s] = '\0';

	tkn = strtok(cp, dlmtr);
	arra = malloc((sizeof(char *) * 2));
	arra[0] = r_strdup(tkn);
	s = 1;
	z = 3;
	while (tkn)
	{
		tkn = strtok(NULL, dlmtr);
		arra = n_realloc(arra, (sizeof(char *) * (z - 1)), (sizeof(char *) * z));
		arra[s] = r_strdup(tkn);
		s++;
		z++;
	}
	free(cp);
	return (arra);
}

/**
 * execution -a function that exec commnd
 *
 * @argv:arg array of args
 */

void execution(char **argv)
{

	int s, sta;

	if (!argv || !argv[0])
		return;
	s = fork();
	if (s == -1)
	{
		perror(n_getenv("_"));
	}
	if (s == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&sta);
}

/**
 * n_realloc -a function that reallocates heap memory
 * @pntr:arg  previous ptr
 * @prv_size:arg previous  size of previous ptr
 * @n_size:arg new size for ptr
 * Return: new ptr with different size
 */

void *n_realloc(void *pntr, unsigned int prv_size, unsigned int n_size)
{
	char *nvo;
	char *prv;

	unsigned int z;

	if (pntr == NULL)
		return (malloc(n_size));

	if (n_size == prv_size)
		return (pntr);

	if (n_size == 0 && pntr != NULL)
	{
		free(pntr);
		return (NULL);
	}

	nvo = malloc(n_size);
	prv = pntr;
	if (nvo == NULL)
		return (NULL);

	if (n_size > prv_size)
	{
		for (z = 0; z < prv_size; z++)
			nvo[z] = prv[z];
		free(pntr);
		for (z = prv_size; z < n_size; z++)
			nvo[z] = '\0';
	}
	if (n_size < prv_size)
	{
		for (z = 0; z < n_size; z++)
			nvo[z] = prv[z];
		free(pntr);
	}
	return (nvo);
}

/**
 * free_arr_ptr -a function that free array of ptrs
 *@arra: arg  array of ptrs
 */

void free_arr_ptr(char **arra)
{
	int s;

	for (s = 0; arra[s]; s++)
		free(arra[s]);
	free(arra);
}
