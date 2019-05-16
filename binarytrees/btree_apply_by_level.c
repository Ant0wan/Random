/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:56:59 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/16 18:07:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_file	*create_indiv(t_btree *node)
{
	t_file	*new;

	new = (t_file*)malloc(sizeof(t_file));
	new->node = node;
	new->level = 0;
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

void	apply(t_file *list, void (*applyf)(void *item,int current_level,
			int is_first_elem))
{
	t_file	*tmp;
	static int i;

	while (list)
	{
		tmp = list->next;
		applyf(list->node->item, list->level,
				!list->level || i != list->level ? 1 : 0);
		i = list->level;
		remove_indiv(&list);
		list = tmp;
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_file	*file;
	t_file	*tmp;
	t_file	*origin;

	if (root)
	{
		file = create_indiv(root);
		tmp = file;
		origin = file;
		while (file)
		{
			if (file->node->left)
			{
				tmp->next = create_indiv(file->node->left);
				tmp->next->level = file->level + 1;
				tmp = tmp->next;
			}
			if (file->node->right)
			{
				tmp->next = create_indiv(file->node->right);
				tmp->next->level = file->level + 1;
				tmp = tmp->next;
			}
			file = file->next;
		}
		apply(origin, applyf);
	}
}
