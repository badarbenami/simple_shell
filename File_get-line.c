#include "shell.h"

/*
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 */


/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_input_buf---this functin buffers chained commands.
 * @info: this parameter struct.
 * @buff: this address of buffer.
 * @l: this address of len var.
 *
 * Return: bytes read
 */
ssize_t ft_input_buf(inf_y *info, char **buff, size_t *l)
{
	ssize_t R = 0;
	size_t len_p = 0;

	if (!*l)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, ft_sigintHandler);
#if USE_GETLINE
		R = getline(buff, &len_p, stdin);
#else
		R = ft_getline(info, buff, &len_p);
#endif
		if (R > 0)
		{
			if ((*buff)[R - 1] == '\n')
			{
				(*buff)[R - 1] = '\0';
				R--;
			}
			info->linecount_flag = 1;
			ft_remove_comments(*buff);
			ft_build_history_list(info, *buff, info->histcount++);
			{
				*l = R;
				info->cmd_buf = buff;
			}
		}
	}
	return (R);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_get_input - this function is gets a line minus the newline.
 * @info: this parameter struct.
 *
 * Return: bytes read.
 */
ssize_t ft_get_input(inf_y *info)
{
	static char *buff;
	static size_t a, b, l;
	ssize_t R = 0;
	char **buf_p = &(info->arg), *p;

	ft_putchar(BUF_FLUSH);
	R = ft_input_buf(info, &buff, &l);
	if (R == -1)
		return (-1);
	if (l)
	{
		b = a;
		p = buff + a;

		ft_check_chain(info, buff, &b, a, l);
		while (b < l)
		{
			if (ft_is_chain(info, buff, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= l)
		{
			a = l = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (ft_strlen(p));
	}

	*buf_p = buff;
	return (R);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_read_buf - this function is reads a buffer.
 * @info: this parameter struct.
 * @buf: this buffer.
 * @size: this size.
 * Return: R.
 */
ssize_t ft_read_buf(inf_y *info, char *buf, size_t *size)
{
	ssize_t g = 0;

	if (*size)
		return (0);
	g = read(info->readfd, buf, READ_BUF_SIZE);
	if (g >= 0)
		*size = g;
	return (g);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_getline - this function gets the next line of input from STDIN.
 * @info: this parameter struct.
 * @ptr: this address of pointer to buffer, preallocated or NULL.
 * @len: size of preallocated ptr buffer if not NULL.
 *
 * Return: s.
 */
int ft_getline(inf_y *info, char **ptr, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, l;
	size_t b;
	ssize_t R = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && len)
		s = *len;
	if (a == l)
		a = l = 0;

	R = ft_read_buf(info, buf, &l);
	if (R == -1 || (R == 0 && l == 0))
		return (-1);

	c = ft_strchr(buf + a, '\n');
	b = c ? 1 + (unsigned int)(c - buf) : l;
	new_p = ft_realloc(p, s, s ? s + b : b + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		ft_strncat(new_p, buf + a, b - a);
	else
		ft_strncpy(new_p, buf + a, b - a + 1);

	s += b - a;
	a = b;
	p = new_p;

	if (len)
		*len = s;
	*ptr = p;
	return (s);
}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * ft_sigintHandler - this function is blocks ctrl-C.
 * @sig_num: this signal nmbr.
 *
 * Return: void.
 */
void ft_sigintHandler(__attribute__((unused))int sig_num)
{
	ft_puts("\n");
	ft_puts("$ ");
	ft_putchar(BUF_FLUSH);
}
