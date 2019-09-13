#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	FILE	*stream = NULL;
	char	buffer[8192];
	size_t	ret = 0;
	int	i = 1;

	if (argc < 2)
		return (EXIT_FAILURE);
	while (i < argc)
	{
		stream = fopen(argv[i], "r");
		if (!stream)
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
		while ((ret = fread((void*)buffer, sizeof(char), sizeof(buffer) - 1, stream)))
		{
			buffer[ret] = '\0';
			if (fwrite((const void*)buffer, sizeof(char), ret, stdout) != ret)
				perror(NULL);
		}
		if (fclose(stream))
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}
