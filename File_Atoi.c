#include "shell.h"

/*
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
*/

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_interactive - this function returns true if shell is interactive mode.
 * @info: this struct address.
 *
 * Return: one if interactive mode, zero otherwise.
 */
int ft_interactive(inf_y *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Code by: BADAR BENAMI, MANEL KHARBOUT.
 * ft_is_delim - this function checks if char is a delimeter.
 * @c: this char to check.
 * @delim: this delimeter string.
 * Return: one if true, zero if false.
 */
int ft_is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_isalpha - this function is checks for alphabetic char.
 * @c: The character to input.
 * Return: one if c is alphabetic, zero otherwise.
 */

int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_atoi - this function converts a string to an integer.
 * @str: the string to be converted.
 * Return: zero if no nmbrs in string, converted nmbr otherwise.
 */

int ft_atoi(char *str)
{
	int a, sign = 1, flag = 0, out;
	unsigned int R = 0;

	for (a = 0; str[a] != '\0' && flag != 2; a++)
	{
		if (str[a] == '-')
			sign *= -1;

		if (str[a] >= '0' && str[a] <= '9')
		{
			flag = 1;
			R *= 10;
			R += (str[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		out = -R;
	else
		out = R;

	return (out);
}
