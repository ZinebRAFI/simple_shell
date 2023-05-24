#include "shell.h"


/**
 * n_getenv -a function that finds the variable name, and returns a ptr to the
 * corresponding value string.
 * @name:arg  var name
 * Return: valeur (which is the value)
 */
char *n_getenv(const char *name)
{
	int s, z;
	char *valeur;

	if (!name)
		return (NULL);
	for (s = 0; environ[s]; s++)
	{
		z = 0;
		if (name[z] == environ[s][z])
		{
			while (name[z])
			{
				if (name[z] != environ[s][z])
					break;
				z++;
			}
			if (name[z] == '\0')
			{
				valeur = (environ[s] + z + 1);
				return (valeur);
			}
		}
	}
	return (0);
}


/**
 * end_plus_node -a function that adds a node to
 * the bottom of an list_t list
 * @tete: ptr to ptr of linked list
 * @str: ptr to str in prvious node
 * Return: newaddress of element
 */

list_of_path *end_plus_node(list_of_path **tete, char *str)
{

	list_of_path *tprary;
	list_of_path *n;

	n = malloc(sizeof(list_of_path));

	if (!str || !n)
	{
		return (NULL);
	}

	n->dir = str;

	n->p = '\0';
	if (!*tete)
	{
		*tete = n;
	}
	else
	{
		tprary = *tete;

		while (tprary->p)
		{

			tprary = tprary->p;
		}

		tprary->p = n;
	}

	return (*tete);
}
