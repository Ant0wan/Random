#include <unistd.h>
#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_input_term();
	else if (argc >= 2)
		while (i < argc)
			ft_tail(argv[i++]);
	return (0);
}
