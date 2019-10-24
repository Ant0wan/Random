/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:23:21 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/15 10:08:41 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*ptr;

	if (!root)
		return (NULL);
	if ((ptr = btree_search_item(root->left, data_ref, cmpf)))
		return (ptr);
	if (!(cmpf(data_ref, root->item)))
		return (root);
	return (btree_search_item(root->right, data_ref, cmpf));
}
