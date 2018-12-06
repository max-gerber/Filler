/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:33:32 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/02 14:39:34 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char		*ft_itoa(int i)
{
	char *s;

	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (i < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-i));
	}
	else if (i >= 10)
	{
		s = ft_strjoin(ft_itoa(i / 10), ft_itoa(i % 10));
	}
	else if (i < 10)
	{
		s[0] = (char)i + 48;
		s[1] = '\0';
	}
	return (s);
}
