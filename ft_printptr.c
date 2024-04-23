/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:35:11 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/23 15:46:59 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(void *p)
{
	int i;
	unsigned long long ptr;

	ptr = (uintptr_t)p;
	i = 0;
	ft_putstr("0x");
	if (ptr == 0)
	{
		ft_putchar('0');
		return ;
	}
	ft_putptr(ptr);
}