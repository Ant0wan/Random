/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:08:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/21 17:36:21 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_btree_rb.h"
#include <stdio.h>

t_rb_node	*insert_data(t_rb_node *root, void *item,
		int (*cmpf)(void *, void *))
{
	while (root)
	{
		if (cmpf(root->data, item) > 0)
		{
			if (root->left)
				root = root->left;
			else if ((root->left = (t_rb_node*)btree_create_node(item)))
				return (root);
		}
		else
		{
			if (root->right)
				root = root->right;
			else if ((root->right = (t_rb_node*)btree_create_node(item)))
				return (root);
		}
	}
	if (!root)
		root = (t_rb_node*)btree_create_node(item);
	return (root);
}

void		rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *))
{
	t_rb_node	*node;

	node = insert_data(*root, data, cmpf);
	node->color = RB_RED;
	printf("color %d,%s\n", node->color, (char*)node->data);
	(void)root;
	(void)data;
	(void)cmpf;
}
