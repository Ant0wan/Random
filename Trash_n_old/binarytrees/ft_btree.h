/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:18:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/17 16:17:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <stdlib.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_file
{
	t_btree			*node;
	int				level;
	struct s_file	*next;
}					t_file;

t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *));
void				*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *));
int					btree_level_count(t_btree *root);
void				btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level,
			int is_first_elem));

#endif
