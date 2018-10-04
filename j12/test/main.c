#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h> // DEBUGGING

#define BUFF_SIZE 63

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	ret;
	char	buf[BUFF_SIZE + 1];

	(void)argc;
	errno = 0;
	fd = open(argv[1], O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	return (errno);
}
