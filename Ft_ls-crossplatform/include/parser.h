/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:34:05 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/17 15:20:33 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct	s_options
{
	_Bool	l:1;
	_Bool	upr:1;
	_Bool	a:1;
	_Bool	r:1;
	_Bool	t:1;
}				t_options;

int				parser(int argc, char **argv, t_options *options);

#endif
