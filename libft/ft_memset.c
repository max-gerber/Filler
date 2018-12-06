/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:47:02 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/24 12:40:03 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *new;

	if (n == 0)
		return (str);
	new = (unsigned char*)str;
	while (n--)
	{
		*new = (unsigned char)c;
		if (n)
			new++;
	}
	return (str);
}
