/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:28:03 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 17:59:40 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "client.h"

int		main(int argc, char **argv)
{
	int		ret;
	int		pid_server;
	pid_t	pid;

	if (argc < 2)
		return (0);
	pid = getpid();
	pid_server = ft_atoi(argv[1]);
	ret = connection_protocol(pid_server, ft_itoa(pid));
	if (ret == 1)
		ret = send_strlen(pid_server, ft_strlen(argv[2]));
		if (ret == 1)
			ret = talk_protocol(argv[2], pid_server);
	if (ret == 0)
		write(2, "Error: Connection problem.\n", 26);
	return (0);
}
