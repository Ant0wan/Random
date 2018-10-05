#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "ft_tail.h"

#define BUF_SIZE 10

#include <stdio.h> // DEBUGGING


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_input_term(void)
{
	return ;
}

void	ft_tail(char *file_name)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	return ;
}
