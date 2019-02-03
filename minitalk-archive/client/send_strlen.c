/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:44:35 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 18:47:16 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "client.h"


static void send_char(pid_t pid, char c)
{
	int	bit;

	bit = 4;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(MSEC);
	}
}

static int	send_strl_to_server(pid_t server_pid, char *strl)
{
	int	i;

	i = -1;
	if (server_pid == 0 || strl == NULL || *strl == 0)
		return (1);
	while (strl[++i])
		send_char(server_pid, strl[i]);
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
	else if (signal == SIGUSR2)
		*received_cpy = 1;
}

int		send_strlen(pid_t server_pid, size_t strl)
{
	int	received;

	received = 0;
	signal(SIGUSR1, (void (*)(int))server_answer);
	signal(SIGUSR2, (void (*)(int))server_answer);
	server_answer(-1, &received);
	while (received == 0)
		sleep(MSEC);
	while (received)
	{
		if (send_strl_to_server(server_pid, ft_itoa(strl)))
			return (-1);
	}
	return (1);
}