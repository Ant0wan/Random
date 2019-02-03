/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:34:12 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 18:48:23 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	get_strlen_client(int signo, size_t *length)
{
	static size_t	*strl;
	static size_t 	tmp_l;
	static char 	buf[4];
	static int		bit;
	size_t			mask;

	if (signo == -1 && (strl = length))
		return ;
	mask = 0;
	buf[bit] = signo == SIGUSR1 ? 1 : 0;
	++bit;
	if (bit == 4)
	{
		tmp_l *= 10;
		mask ^= ((buf[0] & 0x01) << 3) & ~ 0x07;
		mask ^= ((buf[1] & 0x01) << 2) & ~ 0x03;
		mask ^= ((buf[2] & 0x01) << 1) & ~ 0x01;
		mask ^= buf[3] & 0x01;
		bit = 0;
		if (mask == 0b1111)
			*strl = tmp_l / 10;
		tmp_l += mask;
	}
	kill(g_pidc, SIGUSR1);
}

int		enable_signal_strlen()
{
	int ret;

	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	ret = kill(g_pidc, SIGUSR1);
	signal(SIGUSR1, (void (*)(int))get_strlen_client);
	signal(SIGUSR2, (void (*)(int))get_strlen_client);
	usleep(50);
	if (ret != -1)
		ret = kill(g_pidc, SIGUSR2);
	return (ret);
}

int		get_strlen_message(void)
{
	size_t	length;

	length = 0;
	get_strlen_client(-1, &length);
	enable_signal_strlen();
	while (length == 0)
	{
		signal(SIGUSR1, (void (*)(int))get_strlen_client);
		signal(SIGUSR2, (void (*)(int))get_strlen_client);
	}
	kill(g_pidc, SIGUSR1);
	message_client(length, 0); // put in second arg the checksum given in the first protocol
	return (0);
}
