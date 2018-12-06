/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:27:29 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 14:12:45 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t d_size;
	size_t s_size;
	size_t i;

	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (d_size);
	if (size - 1 <= d_size)
		return (s_size + size);
	while ((size - 1 > d_size + i) && src[i])
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (d_size + s_size);
}
