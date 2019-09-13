/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:46:15 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/19 14:55:41 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READDIR_H
# define READDIR_H
# include "parser.h"

char	*concat_path(char *path, char *d_name);

int		feed_readdir_with_each_argument(int argc, char **argv, int i,
		t_options options);

int		store_readdir_output(char *prog_name, char *path, t_options options,
		int first);

#endif
