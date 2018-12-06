/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:31:06 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/02 14:40:15 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	a;
	size_t	size;

	while (s)
	{
		a = 0;
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
			a++;
		if (!s[a])
			return (ft_strdup(s + a));
		size = ft_strlen(s) - 1;
		while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
			size--;
		return (ft_strsub(s, a, size - a + 1));
	}
	return (NULL);
}
