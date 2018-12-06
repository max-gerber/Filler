/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:31:53 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 12:56:17 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *fdest;
	char *fsrc;

	fdest = dest;
	fsrc = (char*)src;
	while (*fdest)
		fdest++;
	while (*fsrc && n--)
		*fdest++ = *fsrc++;
	*fdest = '\0';
	return (dest);
}
