#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_tail.h"

#include <stdio.h> // DEBUGGING

void	ft_input_term(void)
{
	char	input[1];

	while (read(0, input, 1) > 0)
		(void)0;
}

int	ft_input_lines(char *file_name)
{
	char 	buf;
	int	fd;
	int	backslash_nb;

	backslash_nb = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	while (read(fd, &buf, 1) > 0)
		if (buf == '\n')
			backslash_nb++;
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
	return (backslash_nb);
}

int	ft_input_length(char *file_name)
{
	char 	buf;
	int	fd;
	int	length;

	length = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	while (read(fd, &buf, 1) > 0)
		length++;
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
	return (length);
}

int	ft_input_size(char *file_name, int backslash_nb, int c_option_val)
{
	char 	buf;
	int	fd;
	int	size;
	int	count_bs;

	size = 0;
	count_bs = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			count_bs++;
		if (count_bs >= (backslash_nb - c_option_val)) 
			size++;
	}
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
	return (size - 1);
}

void	ft_tail(char *file_name, int size, int length)
{
	int	fd;
	int	ret;
	char	*buf;
	char	c;

	ret = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	buf = (char*)malloc(sizeof(char*) * size + 1);
	while (ret < (length - size))
	{
		ret += read(fd, &c, 1);
	}
	ret += read(fd, buf, size);
	buf[ret] = '\0';
	ft_putstr(buf);
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
}
