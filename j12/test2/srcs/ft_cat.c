#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 30000
#define ERROR_MSG_1 "cat: "
#define ERROR_MSG_2 ": No such file or directory\n"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_puterror(char *argv)
{
	ft_putstr(ERROR_MSG_1);
	ft_putstr(argv);
	ft_putstr(ERROR_MSG_2);
}

void	ft_pstdout(int argc, char *argv)
{
	int	fd;
	int	ret;
	char	buf[BUF_SIZE + 1];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror(argv);
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
		ft_putstr("Close failed\n");
}
