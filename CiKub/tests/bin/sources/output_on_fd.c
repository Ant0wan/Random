#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define YSAGE "Bin badly used: a.out fd message"

int main(int argc, char **argv)
{
	int	fd;

	if (argc == 3)
	{
		fd = atoi(argv[1]);
		if (fd >= 0)
		{
			write(fd, argv[2], strlen(argv[2]));
			return (EXIT_SUCCESS);
		}
	}
	write(STDERR_FILENO, YSAGE, strlen(YSAGE));
	return (EXIT_FAILURE);
}
