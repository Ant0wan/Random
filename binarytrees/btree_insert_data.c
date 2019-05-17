/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:06 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/17 16:46:53 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	while (*root)
	{
		if (cmpf((*root)->item, item) > 0)
		{
			if ((*root)->left)
				*root = (*root)->left;
			else
			{
				(*root)->left = btree_create_node(item);
				break ;
			}
		}
		else
		{
			if ((*root)->right)
				*root = (*root)->right;
			else
			{
				(*root)->right = btree_create_node(item);
				break ;
			}
		}
	}
	if (!*root)
		*root = btree_create_node(item);
}
