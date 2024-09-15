/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:59 by yinhong           #+#    #+#             */
/*   Updated: 2024/09/15 16:05:15 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unbr_len(unsigned int i);
static void	ft_put_unbr(int fd, unsigned int nb);
static void	ft_putunbr_recursion(int fd, unsigned int nb);

int	ft_print_unbr(int fd, unsigned int n)
{
	ft_put_unbr(fd, n);
	return (ft_unbr_len(n));
}

int	ft_unbr_len(unsigned int i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	ft_put_unbr(int fd, unsigned int nb)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_putunbr_recursion(fd, nb);
}

void	ft_putunbr_recursion(int fd, unsigned int nb)
{
	char	mod;

	if (nb != 0)
	{
		mod = nb % 10 + '0';
		ft_putunbr_recursion(fd, nb / 10);
		write(fd, &mod, 1);
	}
}
