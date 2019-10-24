/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:41:37 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/15 10:04:05 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_max(1 + btree_level_count(root->left),
				1 + btree_level_count(root->right)));
}
