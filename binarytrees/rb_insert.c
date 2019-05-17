/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:08:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/17 17:58:53 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_btree_rb.h"

void	rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *))

{
	btree_insert_data((t_btree**)root, data, cmpf);
	(void)root;
	(void)data;
	(void)cmpf;
}
