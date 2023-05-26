#include "shell.h"

/**
 * r_strdup -a function that returns a ptr to an allocated space in memo
 * that contains a cp of str  as a para
 * @str:arg ptr to  str
 * Return: ptr to  str
 */
char *r_strdup(char *str)
{
	int s, z;
	char *n;

	if (!str)
	{
		return (NULL);
	}
	for (z = 0; str[z] != '\0';)
	{
		z++;
	}
	n = malloc(sizeof(char) * z + 1);
	if (n == NULL)
	{
		return (NULL);
	}
	for (s = 0; s < z; s++)
	{
		n[s] = str[s];
	}
	n[z] = str[z];
	free(n);
	return (n);
}

/**
 * n_alloc_concats -a function that concats 3 str
 * in a new allocated memo
 * @nom: 1st string
 * @sp: 2nd string
 * @valeur: 3rd string
 * Return: ptr to new str
 */
char *n_alloc_concats(char *nom, char *sp, char *valeur)
{
	char *rslt;
	int s0;
	int s1;
	int s2;
	int w, z;

	s0 = t_strlen(nom);
	s1 = t_strlen(sp);
	s2 = t_strlen(valeur);

	rslt = malloc(s0 + s1 + s2 + 1);
	if (!rslt)
	return (NULL);
	for (w = 0; nom[w]; w++)
		rslt[w] = nom[w];
	z = w;

	for (w = 0; sp[w]; w++)
		rslt[z + w] = sp[w];
	z += w;

	for (w = 0; valeur[w]; w++)
		rslt[z + w] = valeur[w];
	z += w;
	rslt[z] = '\0';
	return (rslt);
}

/**
 * t_strlen -a function that returns the length of a str
 * @s:arg  ptr to evaluate
 * Return: the length of str
 */
int t_strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}
