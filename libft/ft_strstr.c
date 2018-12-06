/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:10:21 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 14:50:05 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;

	a = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[a])
	{
		b = 0;
		while (haystack[a + b] == needle[b] && haystack[a + b] && needle[b])
			b++;
		if (!needle[b])
			return ((char*)&haystack[a]);
		a++;
	}
	return (NULL);
}
