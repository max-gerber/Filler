/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:52:36 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/01 11:29:10 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *f1;
	char *f2;

	f1 = (char*)s1;
	f2 = (char*)s2;
	if (!n)
		return (1);
	if (s1 && s2 && n)
	{
		while (n--)
		{
			if (*f1 != *f2)
				return (0);
			f1++;
			f2++;
		}
		return (1);
	}
	return (0);
}
