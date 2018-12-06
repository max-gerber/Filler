/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:15:02 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/30 11:16:02 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str1)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (dup == NULL)
		return (NULL);
	return (ft_strcpy(dup, str1));
}
