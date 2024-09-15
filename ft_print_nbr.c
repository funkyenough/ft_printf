/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:57 by yinhong           #+#    #+#             */
/*   Updated: 2024/09/15 16:17:08 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_nbr(int fd, int n);
static int	ft_nbr_len(int i);

int	ft_print_nbr(int fd, int n)
{
	ft_put_nbr(fd, n);
	return (ft_nbr_len(n));
}

int	ft_nbr_len(int i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	else if (i < 0)
		len++;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	ft_put_nbr(int fd, int n)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_put_nbr(fd, nb / 10);
	nb = nb % 10 + '0';
	write(fd, &nb, 1);
}
