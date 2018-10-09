#include <unistd.h>
#include "ft_tail.h"

#define STD_VAL 10

int	main(int argc, char **argv)
{
	int	i;
	int	lines;
	int	size;
	int	std_val;

	std_val = STD_VAL;
	i = 1;
	if (argc == 1)
		ft_input_term();
	while (i < argc)
	{
		if (argc >= 1)
			ft_print_header(argv[i]);
		lines = ft_input_lines(argv[i]);
		size = ft_input_size(argv[i], lines, std_val);
		ft_tail(argv[i], size, ft_input_length(argv[i]));
		i++;
	}
	return (0);
}
