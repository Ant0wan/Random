/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:37:18 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 17:59:40 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H
#include <unistd.h>

# define MSEC 1200
# define CONN_RETRY 10

int			ft_atoi(const char *str);
char		*ft_itoa(int nbr);
void		ft_putnbr_fd(int n, int fd);
int			connection_protocol(pid_t server_pid, char *client_pid);
int			send_strlen(pid_t server_pid, size_t strl);
size_t		ft_strlen(const char *str);
int			talk_protocol(char *str, pid_t pid);

#endif
