/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:52:43 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/02 15:24:46 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	w_c(char const *s, char c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (*s)
	{
		if (a == 1 && *s == c)
			a = 0;
		if (a == 0 && *s != c)
		{
			b++;
			a = 1;
		}
		s++;
	}
	return (b);
}

static int	w_s(char const *s, char c)
{
	int a;

	a = 0;
	while (*s && *s != c)
	{
		a++;
		s++;
	}
	return (a);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w_n;
	char	**array;

	if (!s || !c)
		return (NULL);
	i = 0;
	w_n = w_c(s, c);
	if (!(array = (char**)malloc(sizeof(char*) * (w_n + 1))))
		return (NULL);
	while (w_n--)
	{
		while (*s && *s == c)
			s++;
		if (!(array[i] = ft_strsub((char const*)s, 0, w_s(s, c))))
			return (NULL);
		s += w_s(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
