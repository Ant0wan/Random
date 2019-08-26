/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:43:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 18:26:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_expansion_instances(char *dst, const char *expansion)
{
	int	nb;

	nb = 0;
	while (*dst && (dst = ft_strstr(dst, expansion)))
	{
		++nb;
		++dst;
	}
	return (nb);
}

static char	*malloc_new_line(char *dst, const char *content, const char *expansion,
		int instances)
{
	char	*new;
	size_t	ldst;
	size_t	lcontent;
	size_t	lexpansion;

	ldst = ft_strlen(dst);
	lcontent = ft_strlen(content);
	lexpansion = ft_strlen(expansion);
	if (!(new = (char*)ft_memalloc(sizeof(char) * (instances * (lcontent - lexpansion)
						+ ldst + 1))))
		return (NULL);
	else
		return (new);
}

static void	build_str(char *dst, const char *content, const char *expansion, char *cpy)
{
	char	*ptr;
	char	*expansion_cpy;
	char	*content_cpy;

	content_cpy = NULL;
	while (*dst || ptr)
	{
		if ((ptr = ft_strstr(dst, expansion)))
			content_cpy = (char*)content;
		expansion_cpy = (char*)expansion;
		while (dst < ptr || (!ptr && *dst))
		{
			*cpy = *dst;
			++dst;
			++cpy;
		}
		while (*dst && *expansion_cpy)
		{
			++dst;
			++expansion_cpy;
		}
		while (*content_cpy)
		{
			*cpy = *content_cpy;
			++cpy;
			++content_cpy;
		}
		ptr = NULL;
	}
}

char		*ft_strrep(char **dst, const char *content, const char *expansion)
{
	char	*cpy;
	int		instances;

	if (!expansion || !content || !dst)
		return (NULL);
	instances = count_expansion_instances(*dst, expansion);
	if (!instances)
		return (*dst);
	if (!(cpy = malloc_new_line(*dst, content, expansion, instances)))
		return (NULL);
	build_str(*dst, content, expansion, cpy);
	free(*dst);
	*dst = cpy;
	return (*dst);
}
