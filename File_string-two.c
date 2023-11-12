#include "shell.h"

/*
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 */

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_strcpy - this function is copies a string.
 * @dest: the destination.
 * @src: the source.
 *
 * Return: pointer to destination.
 */
char *ft_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_strdup - fubction is duplicates a string.
 * @str: the string to duplicate.
 *
 * Return: pointer to the duplicated string.
 */
char *ft_strdup(const char *str)
{
	int len = 0;
	char *R;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	R = malloc(sizeof(char) * (len + 1));
	if (!R)
		return (NULL);
	for (len++; len--;)
		R[len] = *--str;
	return (R);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_puts - this function is prints an input string.
 * @str: the string to be printed.
 *
 * Return: Nothing.
 */
void ft_puts(char *str)
{
	int T = 0;

	if (!str)
		return;
	while (str[T] != '\0')
	{
		ft_putchar(str[T]);
		T++;
	}
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_putchar - this function writes the character c to stdout.
 * @c: The char to print.
 *
 * Return: On success one.
 * On error, (-one) is returned, and errno is set appropriately.
 */
int ft_putchar(char c)
{
	static int T;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || T >= WRITE_BUF_SIZE)
	{
		write(1, buf, T);
		T = 0;
	}
	if (c != BUF_FLUSH)
		buf[T++] = c;
	return (1);
}
