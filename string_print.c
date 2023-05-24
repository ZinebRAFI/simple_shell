#include "shell.h"

/**
 * t_putchar - putchar custom function
 * @c: arg char to print
 *
 * Return: 1 is success ||-1 is faillure
 **/
int t_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * t_puts -a function that prints a str
 * @str: ptr to str
 */

void t_puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		t_putchar(str[i]);
		i++;
	}
}
