/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:18:50 by mgerber           #+#    #+#             */
/*   Updated: 2018/06/02 15:18:50 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long b;

	b = n;
	if (b == 0)
		ft_putchar_fd('0', fd);
	if (n && fd)
	{
		if (b < 0)
		{
			ft_putchar_fd('-', fd);
			b *= -1;
		}
		if (b > 9)
		{
			ft_putnbr_fd((b / 10), fd);
		}
		ft_putchar_fd(((b % 10) + '0'), fd);
	}
}
