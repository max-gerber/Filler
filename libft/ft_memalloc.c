/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:48:51 by mgerber           #+#    #+#             */
/*   Updated: 2018/05/31 09:42:44 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*area;

	if (!(area = (void*)malloc(size)))
		return (0);
	ft_memset(area, '\0', size + 1);
	if (area)
		return (area);
	return (NULL);
}
