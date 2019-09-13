/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:29:55 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/15 16:46:06 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# ifdef __unix__

int		print_help(char *prog_name);
int		print_unrec_opt(char *prog_name, char *arg);

# endif

int		print_error(char *restrict prog_name, char *restrict av);
int		print_usage(char *restrict prog_name, char c);

enum		e_error
{
	OK,
	MINOR,
	SERIOUS
};

#endif
