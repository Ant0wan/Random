/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:23:01 by abarthel          #+#    #+#             */
/*   Updated: 2019/10/24 10:25:10 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	FILE	*stream = NULL;
	char	buffer[8192];
	size_t	ret = 0;
	int	i = 1;

	if (argc < 2)
	{
		fprintf(stderr, "usage: %s file ...\n", argv[0]);
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		stream = fopen(argv[i], "r+");
		if (!stream)
		{
			fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
			++i;
			continue ;
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
