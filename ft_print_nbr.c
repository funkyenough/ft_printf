/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:57 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 13:29:25 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_nbr(int n);
static int	ft_nbr_len(int i);

int	ft_print_nbr(int n)
{
	ft_put_nbr(n);
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

void	ft_put_nbr(int n)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_put_nbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}
