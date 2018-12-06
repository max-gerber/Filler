/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:47:01 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 12:22:10 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t i;

	i = ft_strlen((char*)str);
	while (i && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
		return ((char*)&str[i]);
	return (NULL);
}
