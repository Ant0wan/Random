/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:08:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/22 12:53:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_btree_rb.h"
#include <stdio.h>

static t_rb_node	*rb_create_node(void *data, t_rb_node *parent)
{
	t_rb_node	*ptr;

	ptr = (t_rb_node*)0;
	if (!(ptr = (t_rb_node*)malloc(sizeof(t_rb_node))))
		return ((t_rb_node*)0);
	else
	{
		ptr->left = (t_rb_node*)0;
		ptr->right = (t_rb_node*)0;
		ptr->data = data;
		ptr->parent = parent;
		ptr->color = RB_RED;
		return (ptr);
	}
}

static t_rb_node	*insert_data(t_rb_node *root, void *data,
		int (*cmpf)(void *, void *))
{
	while (root)
	{
		if (cmpf(root->data, data) > 0)
		{
			if (root->left)
				root = root->left;
			else if ((root->left = rb_create_node(data, root)))
				return (root->left);
		}
		else
		{
			if (root->right)
				root = root->right;
			else if ((root->right = rb_create_node(data, root)))
				return (root->right);
		}
	}
	if (!root)
		root = rb_create_node(data, (t_rb_node*)0);
	return (root);
}

void				rotation(struct s_rb_node **root,
		struct s_rb_node *node, _Bool clockwise)
{
	t_rb_node	*tmp;

	if (clockwise)
	{
		if (!(tmp = node->parent))
			*root = node->right;
		node->parent = node->right;
		node->right = node->parent->left;
		node->parent->left = node;
		node->parent->parent = tmp;
	}
	else
	{
		if (!(tmp = node->parent))
			*root = node->left;
		node->parent = node->left;
		node->left = node->parent->right;
		node->parent->right = node;
		node->parent->parent = tmp;
	}
}

void				rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *))
{
	t_rb_node	*node;

	if (!(node = insert_data(*root, data, cmpf)))
		return ;
	node->color = RB_BLACK;
}
