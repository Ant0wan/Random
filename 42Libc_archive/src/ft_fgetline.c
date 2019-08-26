/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:48:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/15 15:26:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static __inline__ char	ft_fgetch(const int fd)
{
	int		ret;
	char	ch;

	ret = (int)read(fd, (void*)&ch, 1);
	if (ret == -1)
	{
		return (-1);
	}
	else
	{
		return (ch);
	}
}

static __inline__ char	*create_new_line(char *str, int *len)
{
	char	*new_line;

	new_line = (char*)ft_memalloc(*len);
	if (!new_line)
	{
		*len = -1;
		return (NULL);
	}
	else
	{
		if (str)
		{
			new_line = ft_strncpy(new_line, str, *len);
			free(str);
		}
		return (new_line);
	}
}

int					ft_fgetline(const int fd, char **line, char c)
{
	int		len;
	int		ret;
	char	tmp;
	char	*new_line;

	len = 0;
	ret = 0;
	new_line = NULL;
	while (1)
	{
		len += 128;
		new_line = create_new_line(new_line, &len);
		if (len == -1)
			return (-1);
		*line = new_line;
		while (ret < len)
		{
			tmp = ft_fgetch(fd);
			if (tmp == c || !tmp)
			{
				(*line)[ret] = 0;
				return (ret);
			}
			(*line)[ret] = tmp;
			++ret;
		}
	}
	return (ret);
}
