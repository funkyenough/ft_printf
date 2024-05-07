/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:57 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/07 15:11:48 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n);
int		ft_nbr_len(int i);

int	ft_print_nbr(int n)
{
	ft_putnbr(n);
	return (ft_nbr_len(n));
}

int	ft_nbr_len(int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}
