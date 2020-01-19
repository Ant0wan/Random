#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

static void	sig_int(int signo)
{
	printf("signo:%d\n", signo);
	exit(1);
}

int		main(void)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
		printf("Signal error: %d\n", SIG_ERR);
	while (1);
	return 0;
}
