#include <unistd.h>
#include "ft_tail.h"

#define LEFT_HEADER "==> "
#define RIGHT_HEADER " <==\n"
#define ERROR_MSG_ARG "tail: option requires an argument -- 'c'\n"
#define ERROR_MSG_BYTES "tail: invalid number of bytes: "

void	ft_print_header(char *file_name, int argc, int i)
{
	if (i > 1 && i < argc)
		write(1, "\n", 1);
	ft_putstr(LEFT_HEADER);
	ft_putstr(file_name);
	ft_putstr(RIGHT_HEADER);
}


