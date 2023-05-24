#include "shell.h"

/**
 * signal_handling - checks C^ is pushed
 * @sig_nbr:arg
 */
void signal_handling(int sig_nbr)
{
	if (sig_nbr == SIGINT)
	{
		t_puts("\n#cisfun$ ");
	}
}

/**
 * n_EOF -a function that treats end of file (EOF)
 * @leng:arg return of getline
 * @buffr:arg a buffer
 */
void n_EOF(int leng, char *buffr)
{
	(void)buffr;
	if (leng == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			t_puts("\n");
			free(buffr);
		}
		exit(0);
	}
}
/**
 * n_isatty - verify input from terminal or not
 * Return: no return
 */

void n_isatty(void)
{
	if (isatty(STDIN_FILENO))
		t_puts("#cisfun$ ");
}
