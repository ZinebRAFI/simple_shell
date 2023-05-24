#include "shell.h"

/**
 * exiting -a function that exits shell with || or not return of stat z
 * @arra: array of inputed words
 *
 * return: no return
 */
void exiting(char **arra)
{
	int s, z;

	if (arra[1])
	{
		z = n_atoi(arra[1]);
		if (z <= -1)
			z = 2;
		free_arr_ptr(arra);
		exit(z);
	}
	for (s = 0; arra[s]; s++)
		free(arra[s]);
	free(arra);
	exit(0);
}

/**
 * envr - outputs current envrnmnt
 * @arra:arg array of args
 *
 * Return: no return
 */

void envr(char **arra __attribute__ ((unused)))
{
	int z;

	for (z = 0; environ[z]; z++)
	{
		t_puts(environ[z]);
		t_puts("\n");
	}
}

/**
 * n_atoi -a function that turns a string of chars to int
 * @z:arg  ptr to a str
 * Return: intgr is success
 */
int n_atoi(char *z)
{
	int sig = 1;
	int s;
	int intgr;

	s = 0;
	intgr = 0;
	while (!((z[s] >= '0') && (z[s] <= '9')) && (z[s] != '\0'))
	{
		if (z[s] == '-')
		{
			sig = sig * (-1);
		}
		s++;
	}
	while ((z[s] >= '0') && (z[s] <= '9'))
	{
		intgr = (intgr * 10) + (sig * (z[s] - '0'));
		s++;
	}
	return (intgr);
}

/**
* builtinchecker -a function that checks built in commands
* @arra:arg array of args*
* Return: ptr to fun that accepts arra & returns void
*/
void(*builtinchecker(char **arra))(char **arra)
{
	int i, j;
	ourbuilt T[] = {
		{"exit", exiting},
		{"env", envr},
		{"setenv", n_setenv},
		{"unsetenv", n_unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].nom; i++)
	{
		j = 0;
		if (T[i].nom[j] == arra[0][j])
		{
			for (j = 0; arra[0][j]; j++)
			{
				if (T[i].nom[j] != arra[0][j])
					break;
			}
			if (!arra[0][j])
				return (T[i].fun);
		}
	}
	return (0);
}
