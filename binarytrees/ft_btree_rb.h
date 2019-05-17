/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:40:29 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/17 18:06:18 by abarthel         ###   ########.fr       */
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
	void				*data;
	struct s_rb_node	*parent;
	enum e_rb_color		color;
}						t_rb_node;

void					rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *));
void					rb_remove(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *), void (*freef)(void *));

#endif
