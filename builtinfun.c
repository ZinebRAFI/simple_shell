#include "shell.h"

/**
 * n_setenv - a function that modifies envrnmnt var || Initialize a new one
 * @arra: array of inputs in terminal
 */
void n_setenv(char **arra)
{
	int s, w, z;

	if (!arra[2] || !arra[1])
	{
		perror(n_getenv("_"));
		return;
	}

	for (s = 0; environ[s]; s++)
	{
		w = 0;
		if (arra[1][w] == environ[s][w])
		{
			while (arra[1][w])
			{
				if (arra[1][w] != environ[s][w])
					break;
				w++;
			}
			if (arra[1][w] == '\0')
			{
				z = 0;
				while (arra[2][z])
				{
					environ[s][w + 1 + z] = arra[2][z];
					z++;
				}
				environ[s][w + 1 + z] = '\0';
				return;
			}
		}
	}
	if (!environ[s])
	{
		environ[s] = n_alloc_concats(arra[1], "=", arra[2]);
		environ[s + 1] = '\0';
	}
}

/**
 * n_unsetenv - a function that removes an envrnmnt var
 * @arra: array of inputs in terminal
 */
void n_unsetenv(char **arra)
{
	int s, z;

	if (!arra[1])
	{
		perror(n_getenv("_"));
		return;
	}
	for (s = 0; environ[s]; s++)
	{
		z = 0;
		if (arra[1][z] == environ[s][z])
		{
			while (arra[1][z])
			{
				if (arra[1][z] != environ[s][z])
					break;
				z++;
			}
			if (arra[1][z] == '\0')
			{
				free(environ[s]);
				environ[s] = environ[s + 1];
				while (environ[s])
				{
					environ[s] = environ[s + 1];
					s++;
				}
				return;
			}
		}
	}
}
