/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:05:26 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/26 19:25:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include "display.h"
#include "parser.h"
#include "dlist.h"
#include "error.h"
#include "libft.h"

int			file_info(char *prog_name, char *path, t_options options)
{
	struct stat	statbuf;

	if (stat(path, &statbuf))
		return (print_error(prog_name, path));
	else
		return (display_list_content(&((t_dlist)
						{.statbuf = statbuf, .previous = NULL, .next = NULL,
						.d_name = path, .d_type = 0}), options));
}
