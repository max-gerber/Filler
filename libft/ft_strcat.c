/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:56:30 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 11:54:54 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *fdest;
	char *fsrc;

	fdest = dest;
	fsrc = (char*)src;
	while (*fdest)
		fdest++;
	while (*fsrc)
		*fdest++ = *fsrc++;
	*fdest = '\0';
	return ((char*)dest);
}
