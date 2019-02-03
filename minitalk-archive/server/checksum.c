/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:39:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/02 20:58:43 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	checksum(char *str)
{
	size_t	i;
	int		sum;

	if (!(str) || !(*str))
		return (0);
	i = -1;
	sum = 0;
	while (str[++i])
	{
		sum += (str[i] >> 5) & 0x01 ? 1 : 0;
		sum += (str[i] >> 4) & 0x01 ? 1 : 0;
		sum += (str[i] >> 3) & 0x01 ? 1 : 0;
		sum += (str[i] >> 2) & 0x01 ? 1 : 0;
		sum += (str[i] >> 1) & 0x01 ? 1 : 0;
		sum += str[i] & 0x01 ? 1 : 0;
	}
	return (sum);
}
