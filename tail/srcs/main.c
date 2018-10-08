#include <unistd.h>
#include "ft_tail.h"

#include <stdio.h> // DEBUGGING

#define STD_VAL_C_OPTION 10

int	main(int argc, char **argv)
{
	int	i;
	int	lines;
	int	size;
	int	c_option_val;

	c_option_val = STD_VAL_C_OPTION;
	i = 1;
	if (argc == 1)
		ft_input_term();
	else if (argc >= 2)
	{
		while (i < argc)
		{
			lines = ft_input_lines(argv[i]);
			size = ft_input_size(argv[i], lines, c_option_val);
			ft_tail(argv[i], size, ft_input_length(argv[i]));
			i++;
		}
	}
	return (0);
}
