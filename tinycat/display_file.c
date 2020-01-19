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
	char	buffer[8192];
	FILE	*stream;
	size_t	ret;

	if (argc < 2)
	{
		fprintf(stderr, "usage: %s file ...\n", argv[0]);
		return (EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++)
	{
		stream = fopen(argv[i], "r+");
		if (!stream)
		{
			fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
			continue ;
		}
		while ((ret = fread((void*)buffer, sizeof(char), sizeof(buffer) - 1, stream)))
			if (fwrite((const void*)buffer, sizeof(char), ret, stdout) != ret) perror(NULL);
		if (fclose(stream))
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
