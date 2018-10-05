#include <unistd.h>
#include "ft_tail.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_input_term();
	else if (argc >= 2)
		ft_tail(argc, argv);
	return (0);
}
