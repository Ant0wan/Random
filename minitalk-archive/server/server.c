/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:43:26 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 18:14:47 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "server.h"

void	get_pid_client(int signo)
{
	static int	pid;
	static char buf[4];
	static int	bit;
	int			mask;

	mask = 0;
	buf[bit] = signo == SIGUSR1 ? 1 : 0;
	++bit;
	if (bit == 4)
	{
		pid *= 10;
		mask ^= ((buf[0] & 0x01) << 3) & ~ 0x07;
		mask ^= ((buf[1] & 0x01) << 2) & ~ 0x03;
		mask ^= ((buf[2] & 0x01) << 1) & ~ 0x01;
		mask ^= buf[3] & 0x01;
		bit = 0;
		if (mask == 0b1111)
		{
			g_pidc = pid / 10;
			pid = 0;
		}
		pid += mask;
	}
}

void	signal_pid_client()
{
	signal(SIGUSR1, get_pid_client);
	signal(SIGUSR2, get_pid_client);
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 2);
	write(2, "\n", 1);
	g_pidc = 0;
	while (42)
	{
		if (g_pidc > 0)
		{
			if (get_strlen_message())
				write(2, "Error: PID inconnu.\n", 20);
		}
		else
			signal_pid_client();
	}
	return (0);
}
