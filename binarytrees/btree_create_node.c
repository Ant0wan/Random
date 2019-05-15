/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:23:26 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/15 10:05:30 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*ptr;

	ptr = (t_btree*)0;
	if (!(ptr = (t_btree*)malloc(sizeof(t_btree))))
		return ((t_btree*)0);
	else
	{
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->item = item;
		return (ptr);
	}
}
