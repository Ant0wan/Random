/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:58:26 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/12 11:05:04 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char    **ft_strsplit(char const *s, char c);

void	ft_print_words_tables(char **tab)
{
	int	i;
	int	j;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			wirte(1, &(tab[i][j]), 1;
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	main(void)
{
	char *s;
	int	c;
	size_t	t;

	c = ' ';
	s = "    Hello World  !   ";
	t = nb_words(s, c);
	printf("%zu\n", t);
	ft_print_words_tables(ft_strsplit(s, ' '));
	return(0);
}
