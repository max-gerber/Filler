/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:07:50 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 15:55:42 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int a;
	int b;
	int c;

	a = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[a] && len--)
	{
		b = 0;
		c = len + 1;
		while (haystack[a + b] == needle[b] && haystack[a + b] && needle[b]
				&& c)
		{
			b++;
			c--;
		}
		if (!needle[b])
			return ((char*)&haystack[a]);
		a++;
	}
	return (NULL);
}
