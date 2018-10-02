#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	 return (1); // To be changed for cat behavior
	if (argc >= 2)
		while (i < argc)
		{
			ft_pstdout(argc, argv[i]);
			i++;
		}
	return (0);
}
