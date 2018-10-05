#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_tail.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_input_term(void)
{
	char	input[1];

	while (read(0, input, 1) > 0)
		(void)0;
}

int	ft_input_size(char *file_name)
{
	char 	buf;
	int	fd;
	int	size;

	size = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	while (read(fd, &buf, 1) > 0)
		size++;
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
	return (size);
}

void	ft_tail(char *file_name, int size, int c_option_val)
{
	int	fd;
	int	ret;
	char	*buf;
	char	c;

	ret = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	buf = (char*)malloc(sizeof(char*) * c_option_val + 1);
	while ((ret < (size - c_option_val)))
	{
		ret += read(fd, &c, 1);
	}
	ret += read(fd, buf, c_option_val);
	buf[ret] = '\0';
	ft_putstr(buf);
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
}
