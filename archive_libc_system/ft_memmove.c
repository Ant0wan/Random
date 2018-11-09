/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:19:27 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/08 11:48:33 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;
	unsigned char	buffer[len];

	i = -1;
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	while (++i < len)
		buffer[i] = p_src[i];
	i = -1;
	while (++i < len)
		p_dst[i] = buffer[i];
	return (dst);
}
