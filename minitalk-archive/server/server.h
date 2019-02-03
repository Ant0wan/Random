/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:04:54 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 18:14:47 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H
#include <unistd.h>

#define MSEC 600

void	ft_putnbr_fd(int n, int fd);
int		get_strlen_message(void);
int		message_client(size_t length, int sum_msg);
void	*ft_memalloc(size_t size);
int		checksum(char *str);

pid_t	g_pidc;

#endif
