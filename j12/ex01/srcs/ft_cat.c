#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 30000

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	ft_pstdout(int argc, char **argv)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return ;
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Open failed\n");
			return ;
		}
		ret = read(fd, buf, BUF_SIZE);
		while (ret)
		{
			buf[ret] = '\0';
			ft_putstr(buf);
			ret = read(fd, buf, BUF_SIZE);
		}
		if (close(fd) == -1)
		{
			ft_putstr("Close failed\n");
			return ;
		}
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return ;
	}
}
