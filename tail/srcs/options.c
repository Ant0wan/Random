#include <unistd.h>
#include "ft_tail.h"

#define LEFT_HEADER "==> "
#define RIGHT_HEADER " <==\n"

void	ft_print_header(char *file_name)
{
	ft_putstr(LEFT_HEADER);
	ft_putstr(file_name);
	ft_putstr(RIGHT_HEADER);
}
