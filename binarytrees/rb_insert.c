/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:08:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/17 18:29:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_btree_rb.h"
#include <stdio.h>

void	rb_insert(struct s_rb_node **root, void *data,
		int (*cmpf)(void *, void *))

{
	btree_insert_data((t_btree**)root, data, cmpf);
	printf("color %d\n", (*root)->color);
	(void)root;
	(void)data;
	(void)cmpf;
}
