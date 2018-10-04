#include "ft_cat.h"
#include <errno.h>

int	main(int argc, char **argv)
{
	int	i;
	int	errno;

	i = 1;
	errno = 0;
	if (argc == 1)
		ft_write_input();
	if (argc >= 2)
		while (i < argc)
			ft_pstdout(argc, argv[i++]);
	return (errno);
}
