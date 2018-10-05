#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
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

void	ft_input_size(char *file_name, int *input_size)
{
	char 	buf;
	int	fd;

	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
		*input_size = *input_size + 1;
	close(fd);
}

void	ft_tail(char *file_name)
{
	int	fd;
	int	ret;
	int	input_size;
	char	*buf;

	input_size = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr(ERRMSG_OPEN);
	ft_input_size(file_name, &input_size);
	buf = (char*)malloc(sizeof(char*) * input_size + 1);
	while ((ret = read(fd, buf, input_size)))
		buf[ret] = '\0';
	ft_putstr(buf); // review printing dude !!
	if (close(fd) == -1)
		ft_putstr(ERRMSG_CLOSE);
}
