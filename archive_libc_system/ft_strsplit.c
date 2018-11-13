/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:58:26 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/12 12:35:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> // debugg


static size_t	nb_words(const char *s, char c)
{
	static size_t	nb = 0;

	if (!s || !c)
		return (0);
	if (!*s)
		return (nb);
	while (*s == c)
		++s;
	if (*s != c && *s)
	{
		while (*s && *s != c)
			++s;
		++nb;
	}
	if (*s == c)
		return (nb_words(s, c));
	return (nb);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	static size_t	in;
	char	*string;
	char	**array;

	if (!array)
	{
		array = (char**)malloc(sizeof(char*) * nb_words(s, c) + 1);
		in = 0;
	}
	i = 0;
	if (!array)
		return (NULL);
	if (!c || !*s)
		return (NULL);
	while (*s == c)
		++s;
	while (s[i] && s[i] != c)
		++i;
	string = ft_strnew(i + 1);
	i = 0;
	while (*s != c && *s)
	{
		string[i] = *s;
		++s;
		++i;
	}
	array[in] = string;
	printf("%s\n", array[in]); // debugg
	++in;
	if (*s && s)
		return (ft_strsplit(s, c));
	array[in] = "\0";
	return (array);	
}
