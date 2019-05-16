/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:56:59 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/16 13:21:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_btree.h"

t_file	*create_indiv(t_btree *node)
{
	t_file	*new;

	new = (t_file*)malloc(sizeof(t_file));
	new->node = node;
	new->next = NULL;
	return (new);
}

void	remove_indiv(t_file **elem)
{
	if (elem && *elem)
	{
		free(*elem);
		*elem = NULL;
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_file	*file;
	t_file	*up;
	t_file	*tmp;

	file = NULL;
	tmp = NULL;
	up = NULL;
	if (root)
	{
		file = create_indiv(root); //create first element
		tmp = file; // copy beg pointer of the queue
		while (file) //check there is something in queue
		{
			printf("%s\n", file->node->item); // print element in queue
			if (file->node->left)
			{
				tmp->next = create_indiv(file->node->left); // put left tree as elem in list
				tmp = tmp->next; // go to last element in list
			}
			if (file->node->right)
			{
				tmp->next = create_indiv(file->node->right);
				tmp = tmp->next; // go to last element in list
			}
			up = file->next;
			remove_indiv(&file);
			file = up;
		}
	}
}
