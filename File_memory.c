#include "shell.h"


/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_bfree - this function frees a pointer and NULLs the address.
 * @p: address of the pointer to free.
 *
 * Return: one if freed, otherwise zero.
 */
int ft_bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
