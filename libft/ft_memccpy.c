/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:49:58 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/02 13:17:51 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			a;
	unsigned char	*mem_src;
	unsigned char	*mem_dest;

	a = 0;
	mem_src = (unsigned char *)src;
	mem_dest = (unsigned char *)dest;
	while (a < n)
	{
		mem_dest[a] = mem_src[a];
		if (mem_dest[a] == (unsigned char)c)
			return ((void*)(dest + a + 1));
		a++;
	}
	return (NULL);
}
