#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("UID:%d\tGID:%d\n", getuid(), getgid());
	return 0;
}
