/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:06:47 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/02 14:30:33 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	if (str1 <= str2)
		ft_memcpy(str1, str2, n);
	else
	{
		while (n--)
			((char*)str1)[n] = ((char*)str2)[n];
	}
	return (str1);
}
