#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 30000
#define ERROR_MSG_1 "cat: "
#define ERROR_MSG_2 ": No such file or directory\n"
#define ERROR_MSG_3 ": Is a directory\n"

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
	if (errno == 2)
		ft_putstr(ERROR_MSG_2);
	else if (errno == 21)
		ft_putstr(ERROR_MSG_3);
}

void	ft_pstdout(int argc, char *argv)
{
	int	fd;
	int	ret;
	int	errno;
	char	buf[BUF_SIZE + 1];

	errno = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror(argv);
		return ;
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		ft_puterror(argv);
		return ;
	}
	while (ret)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ret = read(fd, buf, BUF_SIZE);
	}
	if (close(fd) == -1)
		ft_putstr("Close failed\n");
}

void	ft_write_input(void)
{
	int	fd;
	int	ret;

	fd = open("input", O_RDWR, S_IRUSR | S_IWUSR);
}
