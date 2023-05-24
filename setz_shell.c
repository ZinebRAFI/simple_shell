#include "shell.h"

/**
 * free_memo_list - frees memory space of a list
 * @tete: ptr to the linked list
 */
void free_memo_list(list_of_path *tete)
{
	list_of_path *memo;

	while (tete)
	{
		memo = tete->p;
		free(tete->dir);
		free(tete);
		tete = memo;
	}
}

/**
 * n_which - a function that finds pathname for a file
 * @nomdoc:arg  file || commnd
 * @tete: head of a list that is linked & contains path directories
 *
 * Return: if pathname of nomdoc then success || if no match then NULL
 */
char *n_which(char *nomdoc, list_of_path *tete)
{
	struct stat status;
	char *str;

	list_of_path *tprary = tete;

	while (tprary)
	{
		str = n_alloc_concats(tprary->dir, "/", nomdoc);
		if (stat(str, &status) == 0)
		{
			return (str);
		}
		free(str);
		tprary = tprary->p;
	}
	return (NULL);
}

/**
 * linkedpaths -a function that makes a
 * linkedlist for path dir
 * @pt:arg str path value
 * Return: ptr to newly made linked list
 */
list_of_path *linkedpaths(char *pt)
{
	list_of_path *tete = '\0';
	char *tkn;
	char *cpt = r_strdup(pt);

	tkn = strtok(cpt, ":");
	while (tkn)
	{
		tete = end_plus_node(&tete, tkn);
		tkn = strtok(NULL, ":");
	}
	return (tete);
}

/**
 * main -The main function for saad&zineb's Shell project
 * Return: 0 is success always
 */

int main(void)
{
	ssize_t leng = 0;
	char *buffr = NULL, *valeur, *nompath, **arra;
	size_t taille = 0;
	list_of_path *tete = '\0';
	void (*s)(char **);

	signal(SIGINT, signal_handling);
	while (leng != EOF)
	{
		n_isatty();
		leng = getline(&buffr, &taille, stdin);
		n_EOF(leng, buffr);
		arra = split_s_to_a(buffr, " \n");
		if (!arra[0] || !arra)
			execution(arra);
		else
		{
			valeur = n_getenv("PATH");
			tete = linkedpaths(valeur);
			nompath = n_which(arra[0], tete);
			s = builtinchecker(arra);
			if (s)
			{
				free(buffr);
				s(arra);
			}
			else if (nompath)
			{
				free(arra[0]);
				arra[0] = nompath;
				execution(arra);
			}
			else if (!nompath)
				execution(arra);
		}
	}
	free_memo_list(tete);
	free_arr_ptr(arra);
	free(buffr);
	return (0);
}
