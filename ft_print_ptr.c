/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:35:11 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/26 10:46:13 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define PREFIX_LENGTH 2
#define POINTER_LENGTH 16

void	ft_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (0 <= num && num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_ptr(void *p)
{
	unsigned long long	ptr;

	ptr = (uintptr_t)p;
	ft_putstr("0x");
	if (ptr == 0)
	{
		ft_putchar('0');
		return (PREFIX_LENGTH + 1);
	}
	ft_putptr(ptr);
	return (PREFIX_LENGTH + POINTER_LENGTH);
}
