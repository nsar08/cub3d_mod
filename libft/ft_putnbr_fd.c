/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:18:03 by nsar              #+#    #+#             */
/*   Updated: 2022/11/22 16:46:11 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	power;
	int	save;

	power = 1;
	save = n;
	if (n < 0)
	{
		power = -1;
		ft_putchar_fd('-', fd);
	}
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		power = power * 10;
	}
	while (power != 0)
	{
		ft_putchar_fd((save / power) + '0', fd);
		save = save - (save / power) * power;
		power = power / 10;
	}
}
