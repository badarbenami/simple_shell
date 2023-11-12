#include "shell.h"

/*
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 */


/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_erratoi - this function converts a string to an integer.
 * @str: the string to be converted.
 * Return: zero if no nmbrs in string, converted nmbr otherwise
 *       (-one) on error.
 */
int ft_erratoi(char *str)
{
	int a = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;
	for (a = 0;  str[a] != '\0'; a++)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			result *= 10;
			result += (str[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_print_error - this functoion prints an error message.
 * @info: this parameter & return info struct.
 * @estr: this string containing specified error type.
 * Return: zero if no numbers in string, converted number otherwise
 *        (-one) on error.
 */
void ft_print_error(inf_y *info, char *estr)
{
	ft_errputs(info->fname);
	ft_errputs(": ");
	ft_print_d(info->line_count, STDERR_FILENO);
	ft_errputs(": ");
	ft_errputs(info->argv[0]);
	ft_errputs(": ");
	ft_errputs(estr);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_print_d - this function prints a decimal (integer) number (base 10).
 * @input: this input.
 * @fd: this filedescriptor to write to.
 *
 * Return: number of char printed.
 */
int ft_print_d(int input, int fd)
{
	int (*__putchar)(char) = ft_putchar;
	int T, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = ft_errputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (T = 1000000000; T > 1; T /= 10)
	{
		if (_abs_ / T)
		{
			__putchar('0' + current / T);
			count++;
		}
		current %= T;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_convert_number - this function is converter function, a clone of itoa.
 * @nbr: this nmbr.
 * @base: this base.
 * @flags: this argument flags.
 *
 * Return: string.
 */
char *ft_convert_number(long int nbr, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = nbr;

	if (!(flags & CONVERT_UNSIGNED) && nbr < 0)
	{
		n = -nbr;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT
 * ft_remove_comments - this function replaces first instance of '#' with '\0'
 * @buff: this address of the string to modify
 *
 * Return: Always zero.
 */
void ft_remove_comments(char *buff)
{
	int a;

	for (a = 0; buff[a] != '\0'; a++)
		if (buff[a] == '#' && (!a || buff[a - 1] == ' '))
		{
			buff[a] = '\0';
			break;
		}
}
