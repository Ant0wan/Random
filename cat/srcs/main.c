#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_write_input();
	if (argc >= 2)
		while (i < argc)
			ft_pstdout(argc, argv[i++]);
	return (0);
}
