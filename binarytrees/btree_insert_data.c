/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:06 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/20 19:43:16 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	tmp = *root;
	while (tmp)
	{
		if (cmpf(tmp->item, item) > 0)
		{
			if (tmp->left)
				tmp = tmp->left;
			else if ((tmp->left = btree_create_node(item)))
				break ;
		}
		else
		{
			if (tmp->right)
				tmp = tmp->right;
			else if ((tmp->right = btree_create_node(item)))
				break ;
		}
	}
	if (!*root)
		*root = btree_create_node(item);
}
