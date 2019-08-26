/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:49:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/25 16:43:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

extern char	*g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;

int	ft_getopt(int argc, char *const argv[], const char *optstring);

#endif
