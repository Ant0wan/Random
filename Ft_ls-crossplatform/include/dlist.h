/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:55:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/25 15:44:40 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H
# include <sys/stat.h>
# include <dirent.h>

typedef struct	s_dlist
{
	struct stat		statbuf;
	struct s_dlist	*previous;
	struct s_dlist	*next;
	char			*d_name;
	unsigned char	d_type;
}				t_dlist;

void			free_entire_dlist(t_dlist *restrict somewhere_in_dlist);
t_dlist			*create_node(t_dlist *restrict previous, t_dlist *restrict next,
		struct dirent *restrict s_dir);

#endif
