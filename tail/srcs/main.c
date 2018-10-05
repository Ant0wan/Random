#include <unistd.h>
#include "ft_tail.h"

#define STD_VAL_C_OPTION 35

int	main(int argc, char **argv)
{
	int	i;
	int	size;
	int	c_option_val;

	c_option_val = STD_VAL_C_OPTION;
	i = 1;
	if (argc == 1)
		ft_input_term();
	else if (argc >= 2)
	{
		// get the size
		while (i < argc)
		{
			size = ft_input_size(argv[i]);
			ft_tail(argv[i++], size, c_option_val);
		}
	}
	return (0);
}
