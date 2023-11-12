#include "shell.h"

/*
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 */

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_errputs --- this function is prints an input string.
 * @str: the string to be printed.
 *
 * Return: Nothing.
 */
void ft_errputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		ft_errputchar(str[a]);
		a++;
	}
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_errputchar - this function is writes the character c to stderr.
 * @c: This char to print.
 *
 * Return: On success one.
 * On error, -one is returned, and errno is set appropriately.
 */
int ft_errputchar(char c)
{
	static int a;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buff, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buff[a++] = c;
	return (1);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_putfd - this function is writes the character c to given fd.
 * @c: This char to print.
 * @fd: This filedescriptor to write to.
 *
 * Return: On success one.
 * On error, (-one) is returned, and errno is set appropriately.
 */
int ft_putfd(char c, int fd)
{
	static int a;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buff, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buff[a++] = c;
	return (1);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_putsfd - this function is prints an input string.
 * @str: this string to be printed.
 * @fd: this filedescriptor to write to.
 *
 * Return: the nmbr of chars put.
 */
int ft_putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += ft_putfd(*str++, fd);
	}
	return (a);
}
