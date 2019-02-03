/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:44:46 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 19:05:41 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int		interpreter(int signo, int worker, size_t *length)
{
	static char		*res;
	static size_t	i;
	static int		bit;

	if (worker == 0)
	{
		res = (char*)malloc(sizeof(char) * *length);
		bit = 7;
	}
	else if (worker > 0)
	{
		if (--bit == -1)
		{
			bit = 6;
			++i;
		}
		if (i < *length)
		{
			res[i] &= ~(1 << 7);
			if (signo == SIGUSR1)
				res[i] |= (1 << bit);
			else if (signo == SIGUSR2)
				res[i] &= ~(1 << bit);
		}
		if (i + 1 == *length && bit == 0)
			return (1);
	}
	else if (worker == -1)
	{
		write(1, res, *length);
	}
	return (0);
}

void	get_message_client(int signo, void *length, void *active)
{
	static size_t	*len;
	static int		*act;

	if (signo == -1)
	{
		len = (size_t*)length;
		act = (int*)active;
	}
	else
	{
		if (interpreter(signo, 1, len))
		{
			*act = 0;
			kill(g_pidc, SIGUSR2);
		}
		usleep(150);
		kill(g_pidc, SIGUSR1);
	}
}

int		message_client(size_t length, int sum_msg)
{
	int 	active;

	active = 1;
	interpreter(-1, 0, &length);
	get_message_client(-1, &length, &active);
	signal(SIGUSR1, (void (*)(int))get_message_client);
	signal(SIGUSR2, (void (*)(int))get_message_client);
	usleep(MSEC);
	kill(g_pidc, SIGUSR2);
	while (active)
	{
		signal(SIGUSR1, (void (*)(int))get_message_client);
		signal(SIGUSR2, (void (*)(int))get_message_client);
	}
	interpreter(-1, -1, &length);
	/*if (checksum(message) != sum_msg) // pour dire checksum pas bon renvoyer le message
		return (-1);*/
	return (0);
}
