/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:57:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/10 14:41:40 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;

	i = -1;
	if (!s)
		return (NULL);
	cpy = (char*)malloc(sizeof(*cpy) * len + 1);
	if (!cpy)
		return (NULL);
	if (start < start + len)
	{
		while (++i < len)
			cpy[i] = s[start + i];
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
