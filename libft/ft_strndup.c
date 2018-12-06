/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:26:55 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/24 12:41:02 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t size)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	return (ft_strncpy(dup, str, size));
}
