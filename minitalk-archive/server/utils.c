/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:52:43 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/03 12:23:56 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	char	*fresh;

	if (size == 0)
		return (NULL);
	if (!(fresh = (void*)malloc(size)))
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}

int		ft_pow(int nbr, int base)
{
	int rtn;

	rtn = 1;
	while (base >= 0)
	{
		rtn *= nbr;
		base--;
	}
	return (rtn);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		tmp;
	int		size;

	size = 0;
	if (n >= 0)
		n = n * -1;
	else
		ft_putchar_fd('-', fd);
	tmp = n;
	while (tmp <= -10)
	{
		tmp /= 10;
		size++;
	}
	while (size >= 0)
	{
		size--;
		tmp = n / ft_pow(10, size) % 10;
		if (tmp < 0)
			tmp *= -1;
		ft_putchar_fd(tmp % 10 + '0', fd);
	}
}

