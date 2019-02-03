/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:29:08 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/02 17:35:31 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int			ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_length_nbr(int nb)
{
	int i;

	i = 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
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

char		*ft_itoa(int nbr)
{
	char	*res;
	int		len;
	int		neg;

	neg = (nbr < 0) ? 1 : 0;
	len = ft_length_nbr(nbr);
	if (len == 1 && nbr == 0)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * (len + neg))))
		return (NULL);
	res[--len + neg] = '\0';
	if (neg > 0)
		res[0] = '-';
	while (--len >= 0)
	{
		if (nbr < 0)
			res[len + neg] = -(nbr % 10) + '0';
		else
			res[len + neg] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	long	i;
	long	rtn;
	char	is_neg;

	i = 0;
	rtn = 0;
	is_neg = '+';
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		is_neg = str[i++];
	if (str[i] == '+' && is_neg == '-')
		return (0);
	i += (str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i] - '0';
		i++;
	}
	if (rtn < 0)
		return ((is_neg != '-') * -1);
	if (is_neg == '-')
		rtn *= -1;
	return ((int)rtn);
}
