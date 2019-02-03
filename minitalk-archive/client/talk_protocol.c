/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_protocol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:04:57 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/03 19:04:44 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"

static void send_ascii(pid_t pid, char c, int *received)
{
	int	bit;

	bit = 7;
	while (--bit > -1)
	{
		*received = 1;
		usleep(150);
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (*received == 1)
			usleep(MSEC);
	}
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

int	talk_protocol(char *str, pid_t pid)
{
	size_t	i;
	int		received;

	i = 0;
	if (!(*str))
		return (-1);
	received = 0;
	signal(SIGUSR1, (void (*)(int))server_answer);
	signal(SIGUSR2, (void (*)(int))server_answer);
	server_answer(-1, &received);
	while (received == 0)
		sleep(MSEC);
	while (str[i])
	{
		send_ascii(pid, str[i], &received);
		++i;
	}
	usleep(MSEC);
	return (0);
}
