/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:40:29 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/22 17:49:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_RB_H
# define FT_BTREE_RB_H
# include <stdlib.h>

enum					e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct			s_rb_node
{
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	struct s_rb_node	*parent;
	void				*data;
	enum e_rb_color		color;
}						t_rb_node;

void					rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *));
void					rb_remove(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *), void (*freef)(void *));

void					rotation(struct s_rb_node **root, struct s_rb_node *node, _Bool clockwise);
void					set_color(struct s_rb_node *node, _Bool branch);

#endif
