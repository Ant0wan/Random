/*
 * DEBUGG PURPOSE
 */

#include "ft_btree.h"
#include "ft_btree_rb.h"
#include <stdio.h>

typedef struct		s_rbfile
{
	t_rb_node		*node;
	int				level;
	struct s_rbfile	*next;
}					t_rbfile;

static t_rbfile	*create_in(t_rb_node *node)
{
	t_rbfile	*new;

	new = (t_rbfile*)malloc(sizeof(t_rbfile));
	new->node = node;
	new->level = 0;
	new->next = NULL;
	return (new);
}

static void		remove_indiv(t_rbfile **elem)
{
	if (elem && *elem)
	{
		free(*elem);
		*elem = NULL;
	}
}

static void		apply(t_rbfile *list, void (*applyf)(void *item,
			int current_level, int is_first_elem, int color))
{
	t_rbfile		*tmp;
	static int	i;

	while (list)
	{
		tmp = list->next;
		applyf(list->node->data, list->level,
				!list->level || i != list->level ? 1 : 0, list->node->color);
		i = list->level;
		remove_indiv(&list);
		list = tmp;
	}
}

void			rb_apply_by_level(t_rb_node *root, void (*applyf)(void *item,
			int current_level, int is_first_elem, int color))
{
	t_rbfile	*file;
	t_rbfile	*tmp;
	t_rbfile	*origin;

	if (root)
	{
		file = create_in(root);
		tmp = file;
		origin = file;
		while (file)
		{
			if (file->node->left && (tmp->next = create_in(file->node->left)))
			{
				tmp->next->level = file->level + 1;
				tmp = tmp->next;
			}
			if (file->node->right && (tmp->next = create_in(file->node->right)))
			{
				tmp->next->level = file->level + 1;
				tmp = tmp->next;
			}
			file = file->next;
		}
		apply(origin, applyf);
	}
}
