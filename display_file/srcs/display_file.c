#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static __inline__ size_t	ft_strlen(char *__restrict__ str)
{
	size_t len = 0;;

	while (str[len])
		++len;
	return (len);
}

static __inline__ void		ft_putstr(char *__restrict__ str)
{
	size_t	len;

	len = ft_strlen(str);
	if (fwrite((const void*)str, sizeof(char), len, stdout) != len)
		perror(NULL);
}

int				main(int argc, char **argv)
{
	FILE	*stream = NULL;
	size_t	ret = 0;
	char	buffer[4096];
	int	i = 1;

	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (EXIT_FAILURE);
	}
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
			ft_putstr(buffer);
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
