/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:35:11 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 13:29:34 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long i);
static void	ft_putptr(unsigned long long num);

int	ft_print_ptr(void *p)
{
	unsigned long long	ptr;

	ptr = (uintptr_t)p;
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return (PREFIX_LENGTH + 1);
	}
	ft_putptr(ptr);
	return (PREFIX_LENGTH + ft_ptr_len((unsigned long long)p));
}

int	ft_ptr_len(unsigned long long i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}

void	ft_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
}
