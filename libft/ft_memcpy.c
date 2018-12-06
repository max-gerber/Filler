/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:01:43 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 09:54:25 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char *dest;
	char *src;

	dest = (char*)str1;
	src = (char*)str2;
	while (n--)
		*dest++ = *src++;
	return (str1);
}
