/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:49:22 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/08 14:02:57 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	diff = 0;
	p_s1 = (unsigned char*)s1;
	p_s2 = (unsigned char*)s2;
	while (p_s1[i] == p_s2[i] && i < n && p_s1[i] && p_s2[i])
		++i;
	if (p_s1[i] != p_s2[i] && i < n)
	{
		diff = (int)p_s1[i] - (int)p_s2[i];
		if (diff != 0)
			return (diff > 0 ? 1 : -1);
	}
	return (0);
}
