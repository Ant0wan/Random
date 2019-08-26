/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:41:29 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/06 21:49:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tabdel(char ***tab)
{
	size_t	i;

	i = 0;
	if (tab && *tab)
	{
		while ((*tab)[i])
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
			++i;
		}
		free((*tab)[i]);
		free(*tab);
		tab = NULL;
	}
}
