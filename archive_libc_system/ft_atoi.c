/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:17:59 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/09 12:46:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -1 : 1;
		++i;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if ((sign == -1 ? MIN_INT : MAX_INT) / 10 < nbr || (sign == -1 ? MIN_INT : MAX_INT) - (str[i] - 48) < nbr * 10)
			return (sign == -1 ? 0 : -1);
		nbr = nbr * 10 + str[i] - 48;
		++i;
	}
	return (nbr * sign);
}
