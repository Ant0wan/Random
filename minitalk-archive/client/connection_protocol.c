/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection_protocol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:02:40 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/03 17:59:40 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "client.h"

static void	send_char(pid_t pid, char c)
{
	if (c & (1 << 3))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(MSEC);
	if (c & (1 << 2))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(MSEC);
	if (c & (1 << 1))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(MSEC);
	if (c & (1 << 0))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(MSEC);
}

static int	send_pid_to_server(pid_t server_pid, char *client_pid)
{
	int	i;

	i = -1;
	if (server_pid == 0 || client_pid == NULL || *client_pid == 0)
		return (1);
	while (client_pid[++i])
		send_char(server_pid, client_pid[i]);
	kill(server_pid, SIGUSR1);
	usleep(MSEC);
	kill(server_pid, SIGUSR1);
	usleep(MSEC);
	kill(server_pid, SIGUSR1);
	usleep(MSEC);
	kill(server_pid, SIGUSR1);
	usleep(MSEC);
	return (0);
}

static void	server_answer(int signal, void *received)
{
	static int *received_cpy;

	if (signal == -1)
		received_cpy = (int *)received;
	if (signal == SIGUSR1)
		*received_cpy = 0;
}

int			connection_protocol(pid_t server_pid, char *client_pid)
{
	int	received;
	int	retry;

	retry = CONN_RETRY;
	received = 1;
	signal(SIGUSR1, (void (*)(int))server_answer);
	signal(SIGUSR2, (void (*)(int))server_answer);
	server_answer(-1, &received);
	while (received && retry > 0)
	{
		if (send_pid_to_server(server_pid, client_pid))
			return (-1);
		--retry;
	}
	return (1);
}
